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
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
int vis[N];
vector<pii> g[4];
int p[N],a[N],b[N];
int main(){
	int n,m;
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%d",&p[i]);
	}
	rep(i,0,n){
		scanf("%d",&a[i]);
	}
	rep(i,0,n){
		scanf("%d",&b[i]);
	}
	rep(i,0,n){
		if(a[i]==b[i]){
			g[a[i]].pb({p[i],i});
		}
		else{
			g[a[i]].pb({p[i],i});
			g[b[i]].pb({p[i],i});
		}
	}
	rep(i,1,4)sort(all(g[i]));
	scanf("%d",&m);
	int pos[4]={0,0,0,0};
	rep(i,0,m){
		int c;
		scanf("%d",&c);
		int flag=0;
		while(pos[c]<g[c].size()){
			if(!vis[g[c][pos[c]].se]){
				vis[g[c][pos[c]].se]=1;
				printf("%d ",g[c][pos[c]].fi);
				++pos[c];
				flag=1;
				break;
			}
			++pos[c];
		}
		if(!flag)printf("-1 ");
	}
}