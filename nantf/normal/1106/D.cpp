#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,el,head[maxn],to[maxn],nxt[maxn];
bool vis[maxn];
priority_queue<int,vector<int>,greater<int> > pq;
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
int main(){
	n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	pq.push(1);vis[1]=true;
	while(!pq.empty()){
		int u=pq.top();pq.pop();
		printf("%d ",u);
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(!vis[v]) pq.push(v),vis[v]=true;
		}
	}
}