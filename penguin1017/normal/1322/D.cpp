#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=2e3+9;
const ll mod=998244353;
int dp[N<<1][N],l[N],s[N],c[N<<1],sum[N];
int main(){
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	rep(i,0,n)scanf("%d",&l[i]);
	rep(i,0,n)scanf("%d",&s[i]);
	rep(i,1,n+m+1)scanf("%d",&c[i]);
	rep(i,0,n)s[i]=c[l[i]]-s[i];
	rep(i,0,N<<1)rep(j,0,N)dp[i][j]=-1000000000;
	rep(i,0,N<<1)dp[i][0]=0;
	per(i,0,n){
		int num=sum[l[i]]+1,L=l[i];
		per(j,1,num+1){
			int cnt=j;
			int val=dp[L][cnt-1]+s[i];
			for(int p=L;cnt;){
			//	cout<<val<<"val\n";
				sum[p]=max(sum[p],cnt);
				dp[p][cnt]=max(dp[p][cnt],val);
				++p;cnt>>=1;
				val+=c[p]*cnt;
			}
			ans=max(ans,val); 
		}
		rep(i,1,n+m+1)dp[i][0]=max(dp[i][0],max(dp[i-1][0],dp[i-1][1]));
	}
	cout<<ans;
}