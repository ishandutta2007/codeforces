#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=998244353;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
template<typename T>
inline void read(T &x){
	x=0;
	bool f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	if(f) x=-x;
}
int n,m,a[maxn],l[maxn],el,head[maxn],to[maxn],nxt[maxn],cnt[maxn],s[maxn];
bool vis[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u){
	vis[u]=true;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(!vis[v]) dfs(v);
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		cnt[l[v]]++;
	}
	while(cnt[l[u]]) l[u]++;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		cnt[l[v]]--;
	}
}
int main(){
	read(n);read(m);
	FOR(i,1,n) read(a[i]);
	FOR(i,1,m){
		int u,v;
		read(u);read(v);
		add(u,v);
	}
	FOR(i,1,n) if(!vis[i]) dfs(i);
	FOR(i,1,n) s[l[i]]^=a[i];
	int at=-1;
	ROF(i,n,0) if(s[i]){at=i;break;}
	if(~at){
		puts("WIN");
		FOR(u,1,n) if(l[u]==at && (a[u]^s[at])<a[u]){
			a[u]^=s[at];
			s[at]=0;
			for(int i=head[u];i;i=nxt[i]){
				int v=to[i];
				a[v]^=s[l[v]];
				s[l[v]]=0;
			}
		}
		FOR(i,1,n) printf("%d ",a[i]);
	}
	else puts("LOSE");
}