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
int n,m,k,sum;
int a[1000001],b[1000001];
int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i);
	F(i,1,n){
		++b[i];
		if(i-a[i]<=0) --b[1];
		else --b[i-a[i]];
	}
	F(i,1,n) b[i]+=b[i-1];
	F(i,1,n) if(b[i]>=0) ++sum;
	printf("%d",sum);
	return 0;
}