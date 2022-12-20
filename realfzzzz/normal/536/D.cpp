#include<algorithm>
#include<queue>
#include<cstring>
#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
    int x=0;
    bool f=0;
    char c=getchar();
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-'){
        f=1;
        c=getchar();
    }
	while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return f?-x:x;
}
const int maxn=2e3+5;
int n,m,s,t,p[maxn];
struct edge{
	int from,to,dist;
	edge(int u,int v,int w):from(u),to(v),dist(w){}
};
vector<edge> edges;
vector<int> g[maxn];
void add_edge(int u,int v,int w){
	g[u].push_back(edges.size());
	edges.push_back(edge(u,v,w));
	g[v].push_back(edges.size());
	edges.push_back(edge(v,u,w));
}
typedef long long ll;
bool done[maxn];
ll d[maxn];
const ll inf=9e18;
typedef pair<ll,int> pii;
void dijkstra(int s){
	for(int i=1;i<=n;i++) d[i]=inf;
	memset(done,0,sizeof(done));
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	d[s]=0;
	pq.push(pii(0,s));
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(done[u]) continue;
		done[u]=1;
		for(int i=0;i<g[u].size();i++){
			edge& e=edges[g[u][i]];
			if(d[e.to]>d[u]+e.dist){
				d[e.to]=d[u]+e.dist;
				pq.push(pii(d[e.to],e.to));
			}
		}
	}
}
int ord[maxn],coln,col[maxn],rown,row[maxn];
inline bool cmp(int a,int b){
	return d[a]<d[b];
}
ll sum[maxn][maxn];
int cnt1[maxn][maxn],cnt2[maxn][maxn];
bool vis[2][maxn][maxn];
ll f[2][maxn][maxn];
ll dp(bool p,int c,int r){
	if(c>=coln||r>=rown) return 0;
	ll& ans=f[p][c][r];
	if(vis[p][c][r]) return ans;
	vis[p][c][r]=1;
	if(p){
		if(cnt2[c+1][r+1]==0) return ans=dp(1,c,r+1);
		else return ans=min(dp(0,c,r+1),dp(1,c,r+1));
	}
	else{
		if(cnt1[c+1][r+1]==0) return ans=dp(0,c+1,r);
		else return ans=max(dp(0,c+1,r),dp(1,c+1,r))+sum[c+1][r+1];
	}
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    n=readint();
    m=readint();
    s=readint();
    t=readint();
    for(int i=1;i<=n;i++) p[i]=readint();
    for(int i=0;i<m;i++){
    	int u,v,w;
    	u=readint();
    	v=readint();
    	w=readint();
    	add_edge(u,v,w);
	}
	dijkstra(s);
	for(int i=1;i<=n;i++) ord[i]=i;
	sort(ord+1,ord+n+1,cmp);
	coln=n;
	col[ord[1]]=1;
	for(int i=2;i<=n;i++)
		if(d[ord[i]]==d[ord[i-1]]){
			col[ord[i]]=col[ord[i-1]];
			coln--;
		}
		else col[ord[i]]=col[ord[i-1]]+1;
	dijkstra(t);
	for(int i=1;i<=n;i++) ord[i]=i;
	sort(ord+1,ord+n+1,cmp);
	rown=n;
	row[ord[1]]=1;
	for(int i=2;i<=n;i++)
		if(d[ord[i]]==d[ord[i-1]]){
			row[ord[i]]=row[ord[i-1]];
			rown--;
		}
		else row[ord[i]]=row[ord[i-1]]+1;
	for(int i=1;i<=n;i++){
		sum[col[i]][row[i]]+=p[i];
		cnt1[col[i]][row[i]]++;
		cnt2[col[i]][row[i]]++;
	}
	for(int i=1;i<=coln;i++) for(int j=rown-1;j>0;j--){
		sum[i][j]+=sum[i][j+1];
		cnt1[i][j]+=cnt1[i][j+1];
	}
	for(int i=coln-1;i>0;i--) for(int j=1;j<=rown;j++)
		cnt2[i][j]+=cnt2[i+1][j];
	ll ans=dp(0,0,0),tot=0;
	for(int i=1;i<=n;i++) tot+=p[i];
	if(ans*2>tot) printf("Break a heart\n");
	else if(ans*2<tot) printf("Cry\n");
	else printf("Flowers\n");
    return 0;
}