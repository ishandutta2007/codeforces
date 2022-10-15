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
 
int t,k,n,m, i,j,jj,mid,b,root,count0,pl,pr;
vector <int> sect[300];
int cap,p[110001],mof[300],l[60001],r[60001],res[60001];
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>n;
   root=0;
   if (n<=2) {cout<<1<<endl<<1; if (n==2) cout<<' '<<1; return 0;}
   for (i=2;i<=sqrt(n+1);i++) if (!p[i])
   {
   	for (j=i*i;j<=n+1;j+=i) p[j]=1;
   }
   cout<<2<<endl;
   for (i=2;i<=n+1;i++) cout<<2-p[i]<<' ';
}
/*
HackerEarth Mock Test
*/