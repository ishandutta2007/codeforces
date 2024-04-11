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
int n,ma=0;
long long k;
int a[100001];
int p[1001];
int main(){
	scanf("%d%I64d",&n,&k);
	For(i,n) scanf("%d",a+i), ma=max(ma,a[i]);
	if(k>n*3){printf("%d",ma); return 0;}
	int l1=1,l2=2,t=n;
	while(1){
		if(a[l1]>a[l2]){
			a[++t]=a[l2];
			if(++p[a[l1]]>=k) {printf("%d",a[l1]); return 0;}
			++l2;
		}
		else{
			a[++t]=a[l1];
			if(++p[a[l2]]>=k) {printf("%d",a[l2]); return 0;}
			++l2; l1=l2-1;
		}
	}
	return 0;
}