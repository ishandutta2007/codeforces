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
#define ppc(x) __builtin_popcount(x)
using namespace std;
const int N=1<<18;
const ll mod=998244353;
ll dp[N][18],val[N],ans[N],f[19][N],cur[19][N];
char s[20][20];
int n;
map<vi,vi> ok;
vi g;
inline void dfs(int s,int x){
	if(s==n){
		int op=(1<<n)-1;
		ll res=0;
		rep(i,0,1<<n){
		//	cout<<val[i]<<"val\n";
			if(ppc(i)&1)res-=val[op^i];
			else res+=val[op^i];
		}
	//	cout<<"???\n";
		for(auto v:ok[g])ans[v]+=res;
	}
	rep(i,0,1<<n)cur[s][i]=val[i];
	for(int i=x;s+i<=n;++i){
		if(s+i!=n&&s+i+i>n)continue;
		rep(mask,0,1<<n)val[mask]*=f[i][mask];
		g.pb(i);
		dfs(s+i,i);
		rep(mask,0,1<<n)val[mask]=cur[s][mask];
		g.pop_back();
	} 
}
int main(){
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%s",s[i]);
		rep(j,0,n)s[i][j]-=48;
	}
	rep(mask,0,1<<(n-1)){
		vi a;a.clear();
		int pos=0,num=0;
		while(pos<n-1){
			if((mask>>pos)&1)++num;
			else a.pb(num+1),num=0; 
			++pos;
		}
		a.pb(num+1);
		sort(all(a));
	//	cout<<mask<<"mask: ";
	//	for(auto v:a)cout<<v<<' ';
	//	cout<<endl;
		ok[a].pb(mask); 
	}
	rep(i,0,n)dp[1<<i][i]=1;
	rep(mask,0,1<<n){
		rep(i,0,n){
			if(mask&(1<<i)){
				rep(j,0,n)if(((~mask>>j)&1)&&s[i][j])dp[mask|(1<<j)][j]+=dp[mask][i];
			}
			f[ppc(mask)][mask]+=dp[mask][i];
		}
	}
	rep(len,1,n+1){
		rep(i,0,n){
			rep(mask,0,1<<n){
				if((~mask>>i)&1)f[len][mask|(1<<i)]+=f[len][mask];
			}
		}
	}
//	rep(len,1,n+1)rep(mask,0,1<<n)cout<<len<<' '<<mask<<' '<<f[len][mask]<<"f\n";
	rep(i,0,1<<n)val[i]=1;
	dfs(0,1);
	rep(i,0,n-1){
		rep(mask,0,1<<(n-1)){
			if((~mask>>i)&1)ans[mask]-=ans[mask|(1<<i)];
		}
	}
	rep(i,0,1<<n-1)printf("%lld ",ans[i]);
}