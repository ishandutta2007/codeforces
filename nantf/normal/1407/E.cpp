#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=500050,mod=998244353;
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
int n,m,el,head[maxn],to[maxn],nxt[maxn],w[maxn],d[maxn][2],dis[maxn],q[maxn],h,r;
bool vis[maxn];
inline void add(int u,int v,int w_){
	to[++el]=v;nxt[el]=head[u];head[u]=el;w[el]=w_; 
} 
int main(){
	n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read(),w=read();
		add(v,u,w); 
	}
	FOR(i,1,n-1) d[i][0]=d[i][1]=dis[i]=1e9;
	q[h=r=1]=n;
	vis[n]=true;
	while(h<=r){
		int u=q[h++];
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			d[v][w[i]]=min(d[v][w[i]],dis[u]+1);
			dis[v]=max(d[v][0],d[v][1]);
			if(dis[v]<1e9 && !vis[v]) q[++r]=v,vis[v]=true;
		}
	}
	printf("%d\n",dis[1]==1e9?-1:dis[1]);
	FOR(i,1,n) printf("%d",d[i][0]<d[i][1]);
} // calm