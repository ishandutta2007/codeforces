#include<bits/stdc++.h>
using namespace std;
const int maxn=100010,mod=1000000007,d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0;bool f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,f[maxn],ans;
int main(){
	n=read();m=read();
	if(n<m) swap(n,m);
	f[1]=1;f[2]=2;
	FOR(i,3,n) f[i]=(f[i-1]+f[i-2])%mod;
	ans=(f[n]+f[m])%mod;
	ans=(ans-f[1]+mod)%mod;
	printf("%d\n",2*ans%mod);
}