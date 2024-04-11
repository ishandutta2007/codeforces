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
int n,m,k,GCD;
int a[100001];
int f[2001][2001];
int gcd(int x,int y){return x%y==0?y:gcd(y,x%y);}
int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i);
	if(n==1) {puts(a[1]==1?"0":"-1"); return 0;}
	GCD=a[1]; F(i,2,n) GCD=gcd(GCD,a[i]);
	if(GCD!=1) {puts("-1"); return 0;}
 	int cnt=0; F(i,1,n) if(a[i]==1) ++cnt;
 	if(cnt>0) {printf("%d",n-cnt); return 0;}
 	F(i,1,n) f[i][i]=a[i];
	F(Q,2,n){
		F(j,Q,n){
			int i=j-Q+1;
			f[i][j]=gcd(f[i][j-1],a[j]);
			if(f[i][j]==1) {printf("%d",Q+n-2); return 0;}
		}
	}
	return 0;
}