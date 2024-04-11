#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=2020,mod=998244853;
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
int n,m,f[maxn][maxn],g[maxn][maxn],ans;
int main(){
	n=read();m=read();
	f[0][0]=g[0][0]=1;
	FOR(i,0,n) FOR(j,0,m){
		if(!i && !j) continue;
		if(i<j){
			if(i) f[i][j]=(f[i][j]+f[i-1][j])%mod;
			if(j) f[i][j]=(f[i][j]+f[i][j-1])%mod;
		}
		else{
			if(i && i>j) g[i][j]=(g[i][j]+g[i-1][j])%mod;
			if(j) g[i][j]=(g[i][j]+g[i][j-1])%mod;
		}
	}
	FOR(i,0,n) FOR(j,0,m) ans=(ans+1ll*g[i][j]*f[n-i][m-j]%mod*(i-j+mod))%mod;
	printf("%d\n",ans);
}
// 998244853 nmsl