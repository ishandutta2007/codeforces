#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#define ll long long
#define For(i,a) for(int i=1;i<=a;++i)
#define F(i,a,b) for(int i=a;i<=b;++i)
#define dFor(i,a) for(int i=a;i>=1;--i)
#define dF(i,a,b) for(int i=a;i>=b;--i)
#define F2(i,a,b) for(int i=a;i<b;++i)
#define eF(h,i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
ll n,a,b,c,d;
int main(){
	scanf("%lld%lld%lld",&n,&a,&b);
	for(c=0;c*a<=n;++c) if((n-c*a)%b==0) {d=(n-c*a)/b; break;}
	if(c*a>n) {puts("-1"); return 0;}
	for(int j=1;j<=c;++j){
		for(int i=(j-1)*a+1;i<=j*a;++i){
			if(i==j*a) printf("%d ",(j-1)*a+1);
			else printf("%d ",i+1);
		}
	}
	for(int j=1;j<=d;++j){
		for(int i=(j-1)*b+1;i<=j*b;++i){
			if(i==j*b) printf("%d ",a*c+(j-1)*b+1);
			else printf("%d ",a*c+i+1);
		}
	}
	return 0;
}