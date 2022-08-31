#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
#define mp make_pair
#define min(a,b) ((a)<(b)?(a):(b))
const int N=5005;
const int inf=1e9;
inline int read(){
	int x=0,w=1;
	char ch=0;
	while (ch<'0' || ch>'9'){
		ch=getchar();
		if (ch=='-') w=-1;	
	}
	while (ch<='9' && ch>='0'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*w;
}
int n,m,tot,Q;
struct node{
	int x,c,w;
	inline bool operator < (const node &u)const{
		return w<u.w;
	}
}p[N];
struct edge{
	int next,to;
}a[N<<1];
int head[N],cnt;
inline void add(int u,int v){
	a[++cnt].to=v;
	a[cnt].next=head[u];
	head[u]=cnt;
}
priority_queue<pr,vector<pr>,greater<pr> >q;
int d[N][N],vis[N],ps[N];
inline void dij(int s){
	for (int i=1;i<=n;++i) d[s][i]=inf,vis[i]=0;
	d[s][s]=0;
	q=priority_queue<pr,vector<pr>,greater<pr> >();
	q.push(mp(0,s));
	while (!q.empty()){
		int x=q.top().second;
		q.pop();
		if (vis[x]) continue;
		for (int i=head[x];i;i=a[i].next){
			int y=a[i].to;
			if (d[s][y]>d[s][x]+1){
				d[s][y]=d[s][x]+1;
				if (!vis[y]) q.push(mp(d[s][y],y));
			}
		}
	}
}
inline bool chk(int x,int c,int w,int ds){
	ll res=0,now=0;
	for (int i=1;i<=tot;++i){
		if (d[x][p[i].x]<=ds){
			int k=min(p[i].c,c-now);
			now+=k,res+=1ll*p[i].w*k;
			if (res>w) return 0;
		}
	}
	if (now<c) return 0;
	return 1;
}
int main(){
	n=read(),m=read();
	for (int i=1;i<=m;++i){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	tot=read();
	for (int i=1;i<=tot;++i)
		p[i].x=read(),p[i].c=read(),p[i].w=read();
	sort(p+1,p+tot+1);
	Q=read();
	while (Q--){
		int l=0,r=n,ans=-1;
		int x=read(),c=read(),w=read();
		if (!ps[x]) dij(x),ps[x]=1;
		while (l<=r){
			int mid=(l+r)>>1;
			if (chk(x,c,w,mid)) r=mid-1,ans=mid;
			else l=mid+1;
		}
		printf("%d\n",ans);
	}	
	return 0;
}