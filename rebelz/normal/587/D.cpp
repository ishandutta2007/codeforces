#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct edge{
	int u,v,c,t;
}e[50005];

int n,m,tot,ncnt,scnt,cnt;
int v[1000005],nxt[1000005],h[600005],dfn[600005],low[600005],col[600005];
bool ins[600005];
stack<int> s;
vector<int> adj[50005],res;
map<int,int> b[50005];

void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;}

void tarjan(int u){
	dfn[u]=low[u]=++ncnt;
	s.push(u); ins[u]=true;
	for(int p=h[u];p;p=nxt[p]){
		if(!dfn[v[p]]) tarjan(v[p]),chkmin(low[u],low[v[p]]);
		else if(ins[v[p]]) chkmin(low[u],dfn[v[p]]);
	}
	if(low[u]==dfn[u]){
		scnt++;
		do{
			col[u]=scnt;
			u=s.top(); s.pop(); ins[u]=false;
		}while(dfn[u]!=low[u]);
	}
}

bool check(int x,bool kp){
	for(int i=1;i<=n;i++) b[i].clear(),adj[i].clear();
	memset(h,0,sizeof(h)); tot=0,cnt=m;
	for(int i=1;i<=m;i++){
		if(e[i].t>x){
			b[e[i].u][e[i].c]++,b[e[i].v][e[i].c]++;
			if(b[e[i].u][e[i].c]==2||b[e[i].v][e[i].c]==2) return false;
			continue;
		}
		else adj[e[i].u].push_back(i),adj[e[i].v].push_back(i);
	}
	for(int i=1;i<=n;i++) cnt+=adj[i].size()<<1;
	for(int i=1;i<=m;i++) if(e[i].t>x) addedge(i+cnt,i);
	int nowcnt=m;
	for(int i=1;i<=n;i++){
		if(adj[i].size()) addedge(nowcnt+1+cnt,adj[i][0]);
		for(int j=1;j<(int)adj[i].size();j++){
			addedge(nowcnt+j+1+cnt,nowcnt+j+cnt);
			addedge(nowcnt+j+1+cnt,adj[i][j]);
		}
		if(adj[i].size()) addedge(nowcnt+adj[i].size()*2+cnt,adj[i][adj[i].size()-1]);
		for(int j=0;j<(int)adj[i].size()-1;j++){
			addedge(nowcnt+adj[i].size()+j+1+cnt,nowcnt+adj[i].size()+j+2+cnt);
			addedge(nowcnt+adj[i].size()+j+1+cnt,adj[i][j]);
		}
		for(int j=0;j<(int)adj[i].size();j++){
			if(j) addedge(adj[i][j]+cnt,nowcnt+j+cnt);
			if(j+1<(int)adj[i].size()) addedge(adj[i][j]+cnt,nowcnt+adj[i].size()+j+2+cnt);
		}
		nowcnt+=adj[i].size()<<1;
	}
	for(int i=1;i<=n;i++) b[i].clear();
	for(int i=1;i<=m;i++){
		if(b[e[i].u].count(e[i].c)) addedge(b[e[i].u][e[i].c],i+cnt),addedge(b[e[i].u][e[i].c]+cnt,i),addedge(i,b[e[i].u][e[i].c]+cnt),addedge(i+cnt,b[e[i].u][e[i].c]);
		else b[e[i].u][e[i].c]=i;
		if(b[e[i].v].count(e[i].c)) addedge(b[e[i].v][e[i].c],i+cnt),addedge(b[e[i].v][e[i].c]+cnt,i),addedge(i,b[e[i].v][e[i].c]+cnt),addedge(i+cnt,b[e[i].v][e[i].c]);
		else b[e[i].v][e[i].c]=i;
	}
	memset(dfn,0,sizeof(dfn)); ncnt=scnt=0;
	memset(col,0,sizeof(col));
	for(int i=1;i<=cnt+cnt;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=cnt;i++) if(col[i]==col[i+cnt]) return false;
	if(kp){
		for(int i=1;i<=m;i++) if(col[i]>col[i+cnt]) res.push_back(i);
		printf("%d %d\n",x,(int)res.size());
		for(auto r:res) printf("%d ",r);
		printf("\n");
	}
	return true;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++) e[i].u=readint(),e[i].v=readint(),e[i].c=readint(),e[i].t=readint();
	for(int i=1;i<=m;i++){
		b[e[i].u][e[i].c]++,b[e[i].v][e[i].c]++;
		if(b[e[i].u][e[i].c]>2||b[e[i].v][e[i].c]>2) return printf("No\n"),0;
	}
	int l=0,r=1e9+10,ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid,0)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	if(ans<0) return printf("No\n"),0;
	printf("Yes\n");
	check(ans,1);
	return 0;
}