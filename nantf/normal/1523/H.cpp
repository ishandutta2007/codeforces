#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=22222,mod=998244353,INF=1e9;
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
int n,q,a[maxn],to2[15][maxn][33],lt[maxn];
PII to1[15][maxn][33],mx[15][maxn];
struct wtf{
	int a,b,c;
	bool operator<(const wtf &w)const{
		if(a!=w.a) return a<w.a;
		if(b!=w.b) return b>w.b;
		return c>w.c;
	}
};
wtf f[33],g[33];
inline PII query(int l,int r){
	int k=lt[r-l+1];
	return max(mx[k][l],mx[k][r-(1<<k)+1]);
}
int main(){
	n=read();q=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,2,n) lt[i]=lt[i>>1]+1;
	FOR(i,1,n) mx[0][i]=MP(min(n,i+a[i]),i);
	FOR(i,1,lt[n]) FOR(j,1,n-(1<<i)+1) mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
	FOR(i,1,n) FOR(j,0,30) to1[0][i][j]=query(i,min(n,i+a[i]+j));
	FOR(i,1,14) FOR(j,1,n){
		FOR(k,0,30) FOR(l,0,k) to1[i][j][k]=max(to1[i][j][k],to1[i-1][to1[i-1][j][l].second][k-l]);
		FOR(k,1,30) to1[i][j][k]=max(to1[i][j][k],to1[i][j][k-1]);
	}
//	FOR(i,0,14) FOR(j,1,n) FOR(k,0,30) printf("to1[%d][%d][%d]=%d\n",i,j,k,to1[i][j][k].second);
	FOR(i,1,n) FOR(j,0,30) to2[0][i][j]=min(n,i+a[i]+j);
	FOR(i,1,14) FOR(j,1,n){
		FOR(k,0,30) FOR(l,0,k) to2[i][j][k]=max(to2[i][j][k],to2[i-1][to1[i-1][j][l].second][k-l]);
		FOR(k,1,30) to2[i][j][k]=max(to2[i][j][k],to2[i][j][k-1]);
	}
//	FOR(i,0,14) FOR(j,1,n) FOR(k,0,30) printf("to2[%d][%d][%d]=%d\n",i,j,k,to2[i][j][k]);
	while(q--){
		int l=read(),r=read(),m=read();
		if(l==r){puts("0");continue;}
		if(l+a[l]+m>=r){puts("1");continue;}
		FOR(i,0,m) f[i]=(wtf){0,min(n,l+a[l]),l};
		ROF(i,14,0){
			FOR(j,0,m) g[j]=(wtf){INF,0,0};
			FOR(j,0,m) FOR(k,0,m-j){
				int at=f[j].c;
//				printf("to[%d][%d][%d]=%d\n",i,at,k,to2[i][at][k]);
				if(to2[i][at][k]>=r) g[j]=min(g[j],f[j]);
				else{
					wtf w=f[j];
					w.a+=1<<i;
					w.b=to1[i][at][k].first;
					w.c=to1[i][at][k].second;
					g[j+k]=min(g[j+k],w);
				}
			}
			FOR(j,1,m) g[j]=min(g[j],g[j-1]);
			FOR(j,0,m) f[j]=g[j];//,printf("f[%d][%d]=(%d,%d,%d)\n",i,j,f[j].a,f[j].b,f[j].c);
		}
		int ans=INF;
		FOR(i,0,m) if(f[i].b+m-i>=r) ans=min(ans,f[i].a+1);
		printf("%d\n",ans);
	}
}