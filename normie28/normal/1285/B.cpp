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
   cin>>t;
   for (k=1;k<=t;k++)
   {
   	pre.clear();maxx.clear();
   	cin>>n;
   	pre.insert(0);
   	count0=1;
   	a=0;
   	for (i=0;i<n;i++)
   	{
   		cin>>b;
   		a+=b;
   		if ((i==n-1)and(count0==1)) pre.erase(0);
   		maxx.push_back(a-(*(pre.begin())));
   		pre.insert(a);
   		if (a==0) count0++;
   	}
   	sort(maxx.begin(),maxx.end());
   	if (lower_bound(maxx.begin(),maxx.end(),a)!=maxx.end()) cout<<"NO"<<endl;
   	else cout<<"YES"<<endl;
   }
}
/*
1880/1900
*/