#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=400040;
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
int n,el,head[maxn],to[maxn],w[maxn],nxt[maxn];
ll f[maxn][4],ans;
inline void add(int a,int b,int c){
	to[++el]=b;nxt[el]=head[a];head[a]=el;w[el]=c;
}
void dfs(int u,int F){
	ll s=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==F) continue;
		dfs(v,u);
		if(w[i]){
			s+=f[u][0]*(f[v][1]+1);
			s+=f[u][1]*(f[v][0]+2*f[v][1]+f[v][2]+2);
			s+=f[u][2]*(f[v][1]+1);
			s+=f[v][0]+2*f[v][1]+f[v][2]+2;
			f[u][1]+=f[v][1]+1;
			f[u][2]+=f[v][2]+f[v][0];
		}
		else{
			s+=f[u][0]*(2*f[v][0]+f[v][1]+f[v][3]+2);
			s+=f[u][1]*(f[v][0]+1);
			s+=f[u][3]*(f[v][0]+1);
			s+=2*f[v][0]+f[v][1]+f[v][3]+2;
			f[u][0]+=f[v][0]+1;
			f[u][3]+=f[v][3]+f[v][1];
		}
	}
	ans+=s;
}
int main(){
	n=read();
	FOR(i,1,n-1){
		int u=read(),v=read(),w=read();
		add(u,v,w);add(v,u,w);
	}
	dfs(1,0);
	cout<<ans;
}
// orz PB GDOI AK