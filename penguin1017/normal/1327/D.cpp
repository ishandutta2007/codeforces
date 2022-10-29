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
const int N=2e5+9;
const ll mod=998244353;
int vis[N],p[N],c[N],k[N];
vi d[N];
int main(){
	rep(i,1,N){
		for(int j=i+i;j<N;j+=i)d[j].pb(i);
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int ans=n;
		rep(i,1,n+1)scanf("%d",&p[i]);
		rep(i,1,n+1)scanf("%d",&c[i]),vis[i]=0;
		rep(i,1,n+1){
			if(!vis[i]){
				int pos=i,cnt=0;
				while(!vis[pos]){
					++vis[pos];
					k[++cnt]=c[pos];
					pos=p[pos];
				}
				ans=min(ans,cnt);
				for(auto v:d[cnt]){
					if(v>=ans)break;
					int ok=0;
					rep(mask,1,v+1){
						int flag=1;
						for(int j=mask+v;j<=cnt;j+=v){
							if(k[j]!=k[mask]){
								flag=0;
								break;
							}
						}
						if(flag){
							ok=1;
							break;
						}
					}
					if(ok){
						ans=min(ans,v);
						break;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}