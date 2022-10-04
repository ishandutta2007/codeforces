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
int n,m,k,ok,Gcd;
int a[1001];
int gcd(int p1,int p2){return p2!=0?gcd(p2,p1%p2):p1;}
int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i);
	Gcd=a[1]; F(i,2,n) Gcd=gcd(Gcd,a[i]);
	F(i,1,n) if(a[i]/Gcd==1) ok=1;
	if(ok) {printf("%d\n",n+n);F(i,1,n) printf("%d %d ",a[i],Gcd);}
	else puts("-1");
	return 0;
}