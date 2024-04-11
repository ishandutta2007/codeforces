#include <bits/stdc++.h>
using namespace std;
const int MOD=1000*1000*1000+7;
const int N=55;
int n,k,l,r,c[3],C[N<<2][N<<2],f[N][N][2],g[N][N][2];
struct Node{int x,y,z;}q[N*N*2];
inline void add(int&x,int y){x=x+y>=MOD?x+y-MOD:x+y;}
inline void up(int i,int j,int k,int fv,int gv){
	if(i<0||i>c[1]||j<0||j>c[2])return;
	if(!g[i][j][k]){
		f[i][j][k]=fv;
		g[i][j][k]=gv;
		q[++r]=(Node){i,j,k};
	}else if(g[i][j][k]==gv){
		add(f[i][j][k],fv);
	}
} 
int main(){
//	freopen("aa.in","r",stdin);
	int i,j,ui,uj,x;
	scanf("%d%d",&n,&k);k/=50;
	for(C[0][0]=i=1;i<=n;++i)for(C[i][0]=j=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	for(i=1;i<=n;++i)scanf("%d",&x),c[x/50]++;
	f[0][0][0]=1;g[0][0][0]=1;
	q[0]=(Node){0,0,0};
	for(;l<=r;){
		Node t=q[l++];
		for(i=0;i<=k;++i){
			for(j=0;i+2*j<=k;++j)if(i+j){
				if(!t.z){
					if(c[1]-t.x>=0&&c[2]-t.y>=0)up(t.x+i,t.y+j,1,1LL*f[t.x][t.y][t.z]*C[c[1]-t.x][i]%MOD*C[c[2]-t.y][j]%MOD,g[t.x][t.y][t.z]+1);
				}else{
					up(t.x-i,t.y-j,0,1LL*f[t.x][t.y][t.z]*C[t.x][i]%MOD*C[t.y][j]%MOD,g[t.x][t.y][t.z]+1);
				}
			}
		}
	} 
	printf("%d\n%d",g[c[1]][c[2]][1]-1,f[c[1]][c[2]][1]);
	return 0;
}