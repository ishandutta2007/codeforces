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
char lmao[101];
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>t;
   for (k=1;k<=t;k++)
   {
   	cin>>n;
   	for (i=1;i<=n;i++) cin>>lmao[i];
   	j=0;
   	res=0;
   	for (i=1;i<=n;i++) if (lmao[i]=='A')
   	{
   		if ((j)and(res<i-j-1)) res=i-j-1;
   		j=i;
   	}
   	{
   		if ((j)and(res<i-j-1)) res=i-j-1;
   		j=i;
   	}
   	cout<<res<<endl;
   }
}
/*
I don't want a lot for Christmas
There is just one thing I need
I don't care about bi D
That I toang yesterday
I just want you for my own
More than you could ever know
Make my wish come true oh
All I want for Christmas is tm
*/