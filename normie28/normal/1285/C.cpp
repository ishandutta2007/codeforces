#include <bits/stdc++.h>
using namespace std;
 #define MOD 1000000007
 #define A '@'
 #define B '*'
 #define C '#'
 #define max(a,b) ((a>b)?a:b)
 #define min(a,b) ((a<b)?a:b)
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
 
long long t,k,n,m, i,j,jj,mid,a,b,root,count0;
vector <long long> maxx;
long long p[2501],c[2501],res[2501];
multiset<long long> pre;

int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   	pre.clear();maxx.clear();
   	cin>>n;
   	if (n==1) cout<<1<<' '<<1;
   	else
   	{
   		a=1;
   	for (i=1;i<sqrt(n);i++) if ((n%i==0) and (__gcd(i,n/i)==1)) a=i;
   	cout<<a<<' '<<n/a;
   	}
}
/*
1880/1900
*/