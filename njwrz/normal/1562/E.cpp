#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
using namespace std;
char c[5005]; 
int n,dp[5005],rnk[10005],sa[5005],cnt[26],len,to[5005];
bool cmp(int x,int y){
	RE MP(rnk[x],rnk[x+len/2])<MP(rnk[y],rnk[y+len/2]);
}
int h[5005];
void getsa(){
	for(len=2;len<n*2;len<<=1){
		sort(sa+1,sa+n+1,cmp);
		FOR(i,1,n)to[sa[i]]=to[sa[i-1]]+cmp(sa[i-1],sa[i]);
		FOR(i,1,n)rnk[i]=to[i];
	}
}
void geth(){
	int lst=0;
	FOR(i,1,n)if(rnk[i]!=1){
		int x=sa[rnk[i]-1];
		lst=max(0,lst-1);
		while(i+lst<=n&&x+lst<=n&&c[i+lst]==c[x+lst])lst++;
		h[rnk[i]]=lst;
	}
} 
void solve(){
	cin>>n;
	FILL(cnt,0);
	FOR(i,1,n)cin>>c[i],cnt[c[i]-'a']++;
	FOR(i,1,25)cnt[i]+=cnt[i-1];
	FOR(i,n+1,n<<1)rnk[i]=0;
	FOR(i,1,n)rnk[i]=cnt[c[i]-'a'];
	FOR(i,1,n)sa[cnt[c[i]-'a']--]=i;
	getsa();geth();
	FILL(dp,0);
	int ans=0;
	FOR(i,1,n){
//		cout<<sa[i]<<' ';
		gmax(dp[i],n-sa[i]+1);
		int t=n-sa[i]+1;
		FOR(j,i+1,n){
			gmin(t,h[j]);
			if(sa[i]<sa[j])gmax(dp[j],dp[i]+n-sa[j]+1-t);
		}
		gmax(ans,dp[i]);
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}