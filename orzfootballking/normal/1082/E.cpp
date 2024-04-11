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
int sum[500005],cnt[500005],maxi[500005],a[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	FOR(i,1,n){
		cin>>a[i];
		sum[i]=sum[i-1]+(a[i]==k);
	}
	int ans=sum[n];
	FOR(i,1,n){
		maxi[a[i]]=max(maxi[a[i]],sum[i-1]-cnt[a[i]]);
		cnt[a[i]]++;
		ans=max(ans,cnt[a[i]]+maxi[a[i]]+sum[n]-sum[i]);
	}
	cout<<ans;
	RE 0;
}