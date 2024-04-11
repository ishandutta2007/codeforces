#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,k,S[5050][5050];
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans; 
}
int main(){
	n=read();k=read();
	S[0][0]=1;
	FOR(i,1,k) FOR(j,1,i) S[i][j]=(S[i-1][j-1]+1ll*S[i-1][j]*j)%mod;
	int c=1,f=1,ans=0;
	FOR(i,1,min(n,k)){
		c=1ll*c*(n-i+1)%mod*qpow(i,mod-2)%mod;
		f=1ll*f*i%mod;
		ans=(ans+1ll*c*S[k][i]%mod*f%mod*qpow(2,n-i))%mod;
	}
	printf("%d\n",ans);
}