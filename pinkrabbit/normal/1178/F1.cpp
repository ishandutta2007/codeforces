#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 505
#define ll long long
#define mod 998244353
int n,m;
int a[MN];
int f[MN][MN];
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,m)scanf("%d",a+i);
	a[0]=n+1;
	F(i,1,n+1)f[i][i-1]=1;
	F(i,1,n)f[i][i]=1;
	F(q,2,n)F(i,1,n-q+1){
		int j=i+q-1,p=0;
		F(k,i,j)if(a[k]<a[p])p=k;
		ll s1=0,s2=0;
		F(k,i,p)s1=(s1+(ll)f[i][k-1]*f[k][p-1])%mod;
		F(k,p,j)s2=(s2+(ll)f[k+1][j]*f[p+1][k])%mod;
		f[i][j]=s1*s2%mod;
	}
	printf("%d\n",f[1][n]);
	return 0;
}