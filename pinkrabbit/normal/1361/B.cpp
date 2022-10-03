#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 1000005
#define ll long long
#define mod 1000000007
#define inf 0x3f3f3f3f
inline int qpow(int b,ll e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,x;
int a[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&x);
	F(i,1,n)scanf("%d",a+i);
	if(x==1){printf("%d\n",n&1);continue;}
	sort(a+1,a+n+1),reverse(a+1,a+n+1),a[n+1]=0;
	int num=0,flg=0;
	F(i,1,n){
		if(!flg&&!num)num=1;
		else num=(num-1+mod)%mod;
		int d=a[i]-a[i+1];
		while(d){
			if(!num)d=0;
			else if(!flg&&(ll)num*x<mod)num*=x,--d;
			else num=(ll)num*qpow(x,d)%mod,d=0,flg=1;
		}
	}
	printf("%d\n",num);
}	return 0;
}