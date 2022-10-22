#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int ans=0,n,qz[500005],a[500005];
int cnt[500005],dp[500005];
void dfs(int l,int r,int sum){
	if(l==r){
		ans=max(ans,sum+1);RE;
	}
	int mid=(l+r)>>1;
	dfs(l,mid,sum+qz[r]-qz[mid]);
	dfs(mid+1,r,sum+qz[mid]-qz[l-1]);
	for(int i=mid;i>=l;i--){
		cnt[a[i]]++;
		dp[a[i]]=max(dp[a[i]],cnt[a[i]]+qz[i-1]-qz[l-1]);
		ans=max(ans,dp[a[i]]+qz[r]-qz[mid]+sum);
	}
	FOR(i,l,mid)cnt[a[i]]=0;
	FOR(i,mid+1,r){
		cnt[a[i]]++;
		ans=max(ans,dp[a[i]]+cnt[a[i]]+qz[r]-qz[i]+sum);
		ans=max(ans,cnt[a[i]]+qz[r]-qz[i]+qz[mid]-qz[l-1]+sum);
	}
	FOR(i,l,r)dp[a[i]]=cnt[a[i]]=0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin>>n>>k;
	FOR(i,1,n){
		cin>>a[i];
		qz[i]=qz[i-1]+(a[i]==k);
	}
	dfs(1,n,0);
	cout<<ans;
	RE 0;
}