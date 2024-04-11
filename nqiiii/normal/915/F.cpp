#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1000000;
int n,a[maxn+10],id[maxn+10],fa[maxn+10],sz[maxn+10];
vector<int> g[maxn+10]; ll ans; bool b[maxn+10];
bool cmp(int x,int y){return a[x]<a[y];}
int getf(int x){return fa[x]==x?x:fa[x]=getf(fa[x]);}
ll work(){
	ll ans=0;
	for(int i=1;i<=n;++i){
		fa[i]=i; b[i]=0; sz[i]=1;
	}
	for(int i=1;i<=n;++i){
		int x=id[i]; ans+=a[x]; b[x]=1;
		for(int j=0;j<g[x].size();++j){
			int e=g[x][j]; if(!b[e]) continue;
			e=getf(e); ans+=1ll*sz[x]*sz[e]*a[x];
			sz[x]+=sz[e]; fa[e]=x;
		}
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]); id[i]=i;
	}
	for(int i=1;i<n;++i){
		int l,r; scanf("%d%d",&l,&r);
		g[l].push_back(r); g[r].push_back(l);
	}
	sort(id+1,id+n+1,cmp); ans=work();
	reverse(id+1,id+n+1); printf("%lld",ans-work()); return 0;
}