#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
typedef long double LD;
const LD eps=1e-15L;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	printf("? %d\n",2*n+1);
	printf("%d %d\n%d %d\n",0,m,0,0);
	rep(i,n-1)printf("%d %.15Lf\n%d %d\n",i,m-eps,i,0);
	printf("%d %d\n",n,m);
	fflush(stdout);
	LD s;scanf("%Lf",&s);
	LD y=m*s-1.L/2;
	printf("? %d\n",2*m+1);
	printf("%d %d\n%d %d\n",n,0,0,0);
	rep(i,m-1)printf("%.15Lf %d\n%d %d\n",n-eps,i,0,i);
	printf("%d %d\n",n,m);
	fflush(stdout);
	scanf("%Lf",&s);
	LD x=n*s-1.L/2;
	printf("! %.15Lf %.15Lf\n",x,y);
	fflush(stdout);
    return 0;
}