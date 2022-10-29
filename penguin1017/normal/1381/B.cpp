#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
const int N=1e4+9;
const ll mod=998244353;
const ll Inf=1e18;
int n;
int a[N],cnt[N],dp[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		rep(i,1,2*n+1)scanf("%d",&a[i]),cnt[i]=1,dp[i]=0;
		dp[0]=1;
		int p=2*n,pos=2*n;
		while(p){
			int c=0;
			while(a[pos]!=p)cnt[a[pos]]--,--pos,++c;
			cnt[a[pos]]--,--pos,++c;
			//cout<<c<<"c\n";
			per(i,1,n+1){
				if(i<c)break;
				dp[i]|=dp[i-c];
			}
			while(!cnt[p]&&p)--p;
		}
		if(dp[n])printf("YES\n");
		else printf("NO\n");
	}
}