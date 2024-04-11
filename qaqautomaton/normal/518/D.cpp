/*
Author: CNYALI_LK
LANG: C++
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#define up(a,b,c) for (int a(b),end##a(c);a<=end##a;++a)
#define down(a,c,b) for (int a(b),end##a(c);a>=end##a;--a)
#define uup(a,c,b) for (int a(b),end##a(c);a<=end##a;++a)
#define udown(a,b,c) for (int a(b),end##a(c);a>=end##a;--a)
#define endl '\n'
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
const double eps=1e-8;
const double PI=acos(-1.0);
double f[2333][2333];
int main(){
	int n,t;
	double p,ans;
	scanf("%d%lf%d",&n,&p,&t);
	f[0][0]=1;
	up(i,1,t){
	
		f[i][0]=f[i-1][0]*(1-p);
		up(j,1,n-1){
			f[i][j]=f[i-1][j-1]*p+f[i-1][j]*(1-p);
		}
		f[i][n]=f[i-1][n]+f[i-1][n-1]*p;
	}
	ans=0;
	up(i,1,n){
		ans+=f[t][i]*i;
	}
	printf("%lf\n",ans);
	return 0;
}