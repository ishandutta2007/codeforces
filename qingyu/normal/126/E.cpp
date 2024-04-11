// Test
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <set>
#define N 100
#define M 1000
#define int65 unsigned long long
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
const char P[4]={'B','R','W','Y'};
struct ww {
	int x,y;
};
struct w {
	ww a,b;
	int c,d,e;
} c[N],q[20][20][50];
int i,j,k,n,m,an,S,T,t,num,ge;
int a[N][N],h[200],f[N][N],b[N][N],len[N][N],id[N][N],st[N][N],d[N][N],
	ba[M],bb[M],head[M],nxt[M],F[M],g[M],gg[M];
char p[N],s[N][N],re[N][N];
set<int65> Set;
inline void add(int x,int y,int z) {
	ba[++t]=y,bb[t]=z,nxt[t]=head[x],head[x]=t;
	ba[++t]=x,bb[t]=0,nxt[t]=head[y],head[y]=t;
}
inline bool bfs() {
	int l,r,v;
	g[l=r=1]=S; gg[S]=0; F[S]=++num;
	for (;l<=r;l++) for (v=head[g[l]];v;v=nxt[v]) {
		int A=ba[v];
		if (bb[v]&&F[A]!=num) {
			F[A]=num; gg[A]=gg[g[l]]+1; g[++r]=A;
			if (A==T) return 1;
		}
	}
	return 0;
}
int Dfs(int x,int y) {
	if (x==T) return y;
	int v,w=0,re;
	for (v=head[x];v&&w<y;v=nxt[v]) {
		int A=ba[v];
		if (bb[v]&&gg[A]==gg[x]+1&&F[A]==num&&(re=Dfs(A,min(bb[v],y-w))))
			bb[v]-=re,bb[v^1]+=re,w+=re;
	}
	if (!w) gg[x]=0;
	return w;
}
inline void Print(ww A,int B) {
	re[2*A.x-1][2*A.y-1]=P[B];
}
inline void print(w A,int x,int y) {
	if (A.e) swap(A.a,A.b),swap(A.c,A.d);
	if (x!=A.c&&y!=A.d) swap(x,y);
	Print(A.a,x); Print(A.b,y);
}
inline void work() {
	int i,j,u,r;
	For(i,0,3)For(j,i,3) len[i][j]=0;
	For(i,1,ge) {
		w A=c[i];
		q[A.c][A.d][++len[A.c][A.d]]=A;
	}
	int65 hash=0;
	For(i,0,3)For(j,i,3) hash=hash*97+len[i][j];
	if (Set.count(hash)) return;
	Set.insert(hash);
	S=21,T=22; For(i,1,T) head[i]=0; t=1;
	int sum=0;
	For(i,0,3)For(j,i,3) {
		st[i][j]=min(len[i][j],b[i][j]);
		d[i][j]=b[i][j]-st[i][j];
		sum+=st[i][j]*2;
		if (len[i][j]>b[i][j]) add(S,id[i][j],len[i][j]-b[i][j]);
		if (len[i][j]<b[i][j]) add(id[i][j]+10,T,b[i][j]-len[i][j]);
		For(u,0,3)For(r,u,3) {
			if (i==u&&j==r) continue;
			int A=i==u||i==r||j==u||j==r;
			if (A) add(id[i][j],id[u][r]+10,M);
		}
	}
	for (;bfs();sum+=Dfs(S,M));
	if (sum>an) {
		an=sum;
		//print
		memcpy(re,s,sizeof(re));
		For(i,0,3)For(j,0,3) {
			For(k,1,st[i][j]) {
				w B=q[i][j][k];
				print(B,i,j);
			}
			int B=id[i][j],v;
			for (v=head[B];v;v=nxt[v]) {
				int C=ba[v];
				if (C<=10||C>20||bb[v]==M) continue;
				For(u,0,3)For(r,u,3) if (id[u][r]+10==C) goto yy1;
				yy1:;
				int o;
				For(o,bb[v]+1,M) print(q[i][j][++st[i][j]],u,r),d[u][r]--;
			}
		}
		For(i,0,3)For(j,i,3)
		for (;st[i][j]<len[i][j];) {
			int A=++st[i][j];
			For(u,0,3)For(r,u,3) if (d[u][r]) goto yy2;
			yy2:;
			print(q[i][j][A],u,r);
			d[u][r]--;
		}
	}
}
inline void get(int A,int B,ww C,ww D) {
	int a=0;
	if (A>B) swap(A,B),swap(C,D),a=1;
	c[++ge]=(w){C,D,A,B,a};
}
void dfs(int x,int y) {
	if (x>7) {
		work();
		return;
	}
	if (y>8) {
		dfs(x+1,1);
		return;
	}
	if (f[x][y]) {
		dfs(x,y+1);
		return;
	}
	if (x<7) {
		f[x][y]=f[x+1][y]=1;
		get(a[x][y],a[x+1][y],(ww){x,y},(ww){x+1,y});
		s[2*x][2*y-1]='|';
		dfs(x,y+1);
		s[2*x][2*y-1]='.';
		ge--;
		f[x][y]=f[x+1][y]=0;
	}
	if (y<8&&!f[x][y+1]) {
		f[x][y]=f[x][y+1]=1;
		get(a[x][y],a[x][y+1],(ww){x,y},(ww){x,y+1});
		s[2*x-1][2*y]='-';
		dfs(x,y+1);
		s[2*x-1][2*y]='.';
		ge--;
		f[x][y]=f[x][y+1]=0;
	}
}
int main() {
	h['B']=0,h['R']=1,h['W']=2,h['Y']=3;
	For(i,1,7) {
		scanf("%s",p+1);
		For(j,1,8) a[i][j]=h[p[j]];
	}
	For(i,0,3)for (j=3;j>=i;j--) scanf("%d",&b[i][j]);
	k=0; For(i,0,3)For(j,i,3) id[i][j]=++k;
	an=-1; memset(s,'.',sizeof(s));
	dfs(1,1);
	printf("%d\n",an);
	For(i,1,13) {
		For(j,1,15) printf("%c",re[i][j]);
		printf("\n");
	}
	return 0;
}