#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 1005
#define mod 1000000007
int n;
int f[MN],g[MN],ans;
int main(){
	scanf("%d",&n);
	f[0]=1;
	F(i,1,2*n){
		F(j,0,n)g[j]=0;
		F(j,0,n){
			if(j)g[j-1]=(g[j-1]+f[j])%mod;
			if(2*n-i>=j+1)g[j+1]=(g[j+1]+f[j])%mod;
		}
		F(j,0,n)f[j]=g[j];
		if(i&1)F(j,0,n)ans=(ans+f[j])%mod;
	}printf("%d\n",ans);
	return 0;
}