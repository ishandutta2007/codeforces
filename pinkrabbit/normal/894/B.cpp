#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#define For(i,a) for(int i=1;i<=a;++i)
#define F(i,a,b) for(int i=a;i<=b;++i)
#define dFor(i,a) for(int i=a;i>=1;--i)
#define dF(i,a,b) for(int i=a;i>=b;--i)
#define F2(i,a,b) for(int i=a;i<b;++i)
#define eF(h,i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
long long n,m,k;
int Pow(int b,long long e){
	int sum=1;
	while(e){
		if(e&1) sum=1ll*sum*b%1000000007;
		b=1ll*b*b%1000000007; e>>=1;
	} return sum;
}
int main(){
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	if(k==-1&&(n+m)%2==1) puts("0");
	else printf("%d",Pow(Pow(2,n-1),m-1));
	return 0;
}