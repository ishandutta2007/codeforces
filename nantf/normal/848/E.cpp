#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=50050,mod=998244353;
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
int n,f[maxn][2][2][2][2][2],g[maxn][2][2][2][2][2];
void work(int f[][2][2][2][2][2]){
	FOR(i,0,n-2) FOR(a,0,1) FOR(b,0,1) FOR(c,0,1) FOR(d,0,1) FOR(e,0,1){
		if(b){
			if(!a){
				FOR(x,c,1) FOR(y,d,1) FOR(z,e,1) f[i+1][1][1][x][y][z]=(f[i+1][1][1][x][y][z]+f[i][a][b][c][d][e])%mod;
			}
			FOR(x,c,1) FOR(y,d,1) FOR(z,e,1) f[i+1][0][a][x][y][z]=(f[i+1][0][a][x][y][z]+f[i][a][b][c][d][e])%mod;
			if(c && d && !e) f[i+1][1][a][0][0][0]=(f[i+1][1][a][0][0][0]+f[i][a][b][c][d][e])%mod;
		}
		else{
			FOR(x,c,1) FOR(y,d,1) FOR(z,e,1) f[i+1][1][a][x][y][z]=(f[i+1][1][a][x][y][z]+f[i][a][b][c][d][e])%mod;
		}
	}
}
int main(){
	n=read();
	f[0][1][1][0][0][0]=1;
	work(f);
	g[0][1][0][0][0][0]=1;
	work(g);
	int fs=(f[n-1][1][1][1][1][0]+f[n-1][1][1][1][1][1])%mod;
	int gs=(g[n-1][0][1][1][1][0]+g[n-1][0][1][1][1][1])%mod;
	printf("%d\n",(fs+gs)%mod);
}