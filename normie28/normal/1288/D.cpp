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
 
long long t,k,n,m, i,j,jj,mid,b,root,count0;
vector <long long> maxx;
long long a[300001][9],cnt[256],p2;
multiset<long long> pre;
void check(long long l, long long r)
{
	long long mid=(l+r)/2,c; mid++;
	if (l==r)
	{
		long long has[300001];
	//	cout<<mid<<endl;
		for (int i=0;i<=p2;i++) cnt[i]=0;
		for (int i=1;i<=n;i++)
		{
			c=0;
			for (j=1;j<=m;j++)	{c*=2; if (a[i][j]>=l) c++;}
			cnt[c]++; has[i]=c;
		}
		c=0;
		for (int i=0;i<=p2;i++) for (int j=i;j<=p2;j++) if ((cnt[i])and(cnt[j])and((i|j)==p2)) 
		{
		//	cout<<mid<<' '<<i<<' '<<j<<endl;
			for (int ii=1;ii<=n;ii++) if (has[ii]==i) {cout<<ii<<' '; break;}
			for (int ii=1;ii<=n;ii++) if (has[ii]==j) {cout<<ii<<' '; break;}
			return;
		}
	}
	else
	{
		for (int i=0;i<=p2;i++) cnt[i]=0;
		for (int i=1;i<=n;i++)
		{
			c=0;
			for (j=1;j<=m;j++)	{c*=2; if (a[i][j]>=mid) c++;}
			cnt[c]++;
		}
		c=0;
		for (int i=0;i<=p2;i++) for (int j=i;j<=p2;j++) if ((cnt[i])and(cnt[j])and((i|j)==p2)) c=1;
		if (c) check(mid,r); else check(l,mid-1);
	}
}
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>n>>m;
   p2=pow(2,m)-1;
	for (i=1;i<=n;i++)
	for (j=1;j<=m;j++) cin>>a[i][j];
	check(0,1e9+7);
}
/*
1880/1900
n>=2sqrt(d)
a/c <=b

b+1=10ex
*/