#include<bits/stdc++.h>
using namespace std;
const int maxn=777,mod=1e9+7;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,f[maxn][maxn][10][2],ans;
char s[maxn];
int calc(int x){
	int pro=1,s=0;
	FOR(i,1,x){
		s=(s+pro)%mod;
		pro=10ll*pro%mod;
	}
	return s;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	FOR(i,0,9) f[0][0][i][0]=1;
	FOR(i,1,n) FOR(j,0,i) FOR(k,0,9) FOR(l,0,9) if(l<k || j){
		if(l==s[i]-'0') f[i][j][k][0]=(f[i][j][k][0]+f[i-1][j-(l>=k)][k][0])%mod;
		f[i][j][k][1]=(f[i][j][k][1]+f[i-1][j-(l>=k)][k][1])%mod;
		if(l<s[i]-'0') f[i][j][k][1]=(f[i][j][k][1]+f[i-1][j-(l>=k)][k][0])%mod;
	}
	FOR(j,0,n) FOR(k,1,9) ans=(ans+1ll*calc(j)*(f[n][j][k][0]+f[n][j][k][1])%mod)%mod;
	printf("%d\n",ans);
}