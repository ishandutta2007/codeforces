#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=2222,mod=998244353;
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
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,a[maxn][maxn],u[maxn],v[maxn],ans[maxn][2],al,q[maxn],h=1,r;
bool vis[maxn];
void ask(int x){
	printf("? %d\n",x);
	fflush(stdout);
	FOR(i,1,n) a[x][i]=read();
}
/*
int at(){
	int p=0;
	FOR(i,1,n) if(!vis[i] && (!p || a[i]>a[p])) p=i;
	return p;
}
*/
inline void add(int u,int v){
	ans[++al][0]=u;ans[al][1]=v;
}
int main(){
	n=read();
	ask(1);
	int c=0;
	FOR(i,1,n) if(a[1][i]%2==0) c++;
	int tp=c<=n/2?0:1;
	FOR(i,1,n) if(a[1][i]%2==tp){
		if(i!=1) ask(i);
		FOR(j,1,n) if(a[i][j]==1) add(i,j);
	}
	puts("!");
	FOR(i,1,al) printf("%d %d\n",ans[i][0],ans[i][1]);
	fflush(stdout);
}