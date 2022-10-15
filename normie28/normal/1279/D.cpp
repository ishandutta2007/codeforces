#include <bits/stdc++.h>
using namespace std;
 #define MOD 998244353
 #define A '@'
 #define B '*'
 #define C '#'
 #define max(a,b) ((a>b)?a:b)
 #define endl "\n"
 struct frac {long x; long y;};
 frac operator+(frac a, frac b)
 {
 	frac res;
 	res.x=((a.x)*(b.y))%MOD+((b.x)*(a.y))%MOD;
 	res.x%=MOD;
 	res.y=a.y*b.y;
 	res.y%=MOD;
 	return res;
 }
 
 long long bow (long long a, long long x)
 {
 	if (!x) return 1;
	long long res=bow(a,x/2);
	res*=res; res%=MOD;
	if (x%2) res*=a;
	return (res)%MOD;
 }
 
 long long get_mod(long long x, long long y)
 {
 	long long d=__gcd(x,y);
 	x/=d;
 	y/=d;
 	x%=MOD;
 	y%=MOD;
 	return (x*(bow(y,MOD-2)))%MOD;
 }
 
 
long long t,k,n,m, i,j,mid,a,b,c,res;
long long pres[1000001],quan[1000001];
long long pchoose[1000001],h; 
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>n;
   for (i=1;i<=n;i++)
   {
   	cin>>k;
   	for (j=1;j<=k;j++)
   	{
   		cin>>a;
   		pchoose[a]=pchoose[a]+get_mod(1,k*n); pchoose[a]%=MOD;
   		quan[a]++;
   	}
   }
   for (i=1;i<=1000000;i++) {pchoose[i]*=get_mod(quan[i],n); pchoose[i]%=MOD;
   }
   for (i=1;i<=1000000;i++) {h+=pchoose[i]; h%=MOD;}
   cout<<h;
}