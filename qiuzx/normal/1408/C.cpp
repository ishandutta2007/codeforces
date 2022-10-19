#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,l,a[N],sp1,sp2;
long double pl1,pl2,ans=0;
double ot;
int main(){
	ll T,i,j;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&l);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		ans=0;
		i=0;
		j=n-1;
		sp1=sp2=1;
		pl1=(long double)0;
		pl2=(long double)l;
		while(i<=j)
		{
			if(((long double)a[i]-pl1)*(long double)sp2<(pl2-(long double)a[j])*(long double)sp1)
			{
				ans+=((long double)a[i]-pl1)/(long double)sp1;
				pl2-=(((long double)a[i]-pl1)/(long double)sp1)*(long double)sp2;
				pl1=(long double)a[i];
				sp1+=(long double)1;
				i++;
			}
			else
			{
				ans+=(pl2-(long double)a[j])/(long double)sp2;
				pl1+=((pl2-(long double)a[j])/(long double)sp2)*(long double)sp1;
				pl2=(long double)a[j];
				sp2+=(long double)1;
				j--;
			}
		}
		ans+=(pl2-pl1)/(long double)(sp1+sp2);
		ot=ans;
		printf("%.15lf\n",ot);
	}
	return 0;
}