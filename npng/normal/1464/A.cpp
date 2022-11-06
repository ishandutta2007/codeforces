#include <set>
#include <cstdio>
using namespace std;
const int Maxn=100000;
int n,m;
int x[Maxn+5],y[Maxn+5];
int id[Maxn+5];
int nxt[Maxn+5];
bool vis[Maxn+5];
int deg[Maxn+5];
set<int> st;
int qu[Maxn+5],qu_f,qu_t;
void init(){
	st.clear();
	for(int i=1;i<=n;i++){
		nxt[i]=id[i]=0;
		vis[i]=0;
		deg[i]=0;
	}
}
void solve(){
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x[i],&y[i]);
		id[y[i]]=i;
		st.insert(i);
	}
	for(int i=1;i<=m;i++){
		if(id[x[i]]){
			nxt[id[x[i]]]=i;
			deg[i]++;
		}
	}
	qu_f=1,qu_t=0;
	for(int i=1;i<=m;i++){
		if(deg[i]==0){
			qu[++qu_t]=i;
		}
	}
	int ans=m;
	for(int i=1;i<=m;i++){
		if(x[i]==y[i]){
			ans--;
			st.erase(i);
		}
	}
	while(!st.empty()){
		int u;
		if(qu_f<=qu_t){
			u=qu[qu_f++];
		}
		else{
			u=*st.begin();
			ans++;
		}
		st.erase(u);
		if(nxt[u]){
			deg[nxt[u]]--;
			if(deg[nxt[u]]==0&&st.count(nxt[u])>0){
				qu[++qu_t]=nxt[u];
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}