#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,t,k,p[maxn],el,head[maxn],to[maxn],nxt[maxn],q[maxn],h,r,dis[maxn],cnt[maxn],ans1,ans2;
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void bfs(int s){
	MEM(dis,-1);
	q[h=r=1]=s;
	dis[s]=0;
	while(h<=r){
		int u=q[h++];
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[v]==-1){
				dis[v]=dis[u]+1;
				q[++r]=v;
			}
			if(dis[v]==dis[u]+1) cnt[v]++;
		}
	}
}
int main(){
	n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read();
		add(v,u);
	}
	k=read();
	FOR(i,1,k) p[i]=read();
	t=p[k];
	bfs(t);
	FOR(i,1,k-1){
		if(dis[p[i]]!=dis[p[i+1]]+1) ans1++;
		if(dis[p[i]]!=dis[p[i+1]]+1 || cnt[p[i]]>1) ans2++;
	}
	printf("%d %d\n",ans1,ans2);
}