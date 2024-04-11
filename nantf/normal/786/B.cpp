#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
const ll inf=0x3f3f3f3f3f3f3f3f;
struct edge{
	int v,w,nxt;
}e[maxn*20];
struct heap{
	int u;ll dis;
	bool operator<(const heap &h)const{
		return dis>h.dis;
	}
};
int n,m,s,head[maxn*5],el;
int ch[maxn*5][2],cnt,rt1,rt2;
ll dis[maxn*5];
priority_queue<heap> pq;
inline void add(int u,int v,int w){
	e[++el]=(edge){v,w,head[u]};head[u]=el;
}
void build_(int &x,int l,int r,int tp){
	if(l==r) return void(x=l);
	x=++cnt;
	int mid=l+r>>1;
	build_(ch[x][0],l,mid,tp);
	build_(ch[x][1],mid+1,r,tp);
	if(tp==1) add(x,ch[x][0],0),add(x,ch[x][1],0);
	else add(ch[x][0],x,0),add(ch[x][1],x,0);
}
void addedge_(int x,int L,int R,int l,int r,int u,int w,int tp){
	if(L>=l && R<=r) return tp==1?add(u,x,w):add(x,u,w);
	int mid=L+R>>1;
	if(mid>=l) addedge_(ch[x][0],L,mid,l,r,u,w,tp);
	if(mid<r) addedge_(ch[x][1],mid+1,R,l,r,u,w,tp);
}
void build(int &x,int tp){build_(x,1,n,tp);}
void addedge(int x,int u,int l,int r,int w,int tp){addedge_(x,1,n,l,r,u,w,tp);}
void dijkstra(int s){
	while(!pq.empty()) pq.pop();
	memset(dis,0x3f,sizeof(dis));
	pq.push((heap){s,dis[s]=0});
	while(!pq.empty()){
		int u=pq.top().u;ll d=pq.top().dis;pq.pop();
		if(d>dis[u]) continue;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(d+e[i].w<dis[v]) pq.push((heap){v,dis[v]=d+e[i].w});
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	cnt=n;build(rt1,1);build(rt2,2);
	for(int i=1;i<=m;i++){
		int op,w,x,y,z;
		scanf("%d%d%d%d",&op,&w,&x,&y);
		if(op==1) add(w,x,y);
		else if(op==2) scanf("%d",&z),addedge(rt1,w,x,y,z,1);
		else scanf("%d",&z),addedge(rt2,w,x,y,z,2);
	}
	dijkstra(s);
	for(int i=1;i<=n;i++) printf("%lld ",dis[i]==inf?-1ll:dis[i]);
}