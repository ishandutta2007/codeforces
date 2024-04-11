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
int cap,a[60001],mof[300],l[60001],r[60001],res[60001];
int cmp (int x, int y) {return (a[x]<a[y]);}
int check_smaller_or_equal(int x)
{
	int res=0;
	a[200000]=x;
	for (int i=0;i<300;i++) {a[200000]=x-mof[i]; res+=upper_bound(sect[i].begin(),sect[i].end(),200000,cmp)-sect[i].begin();}
	return res;
}
int check_smaller(int x)
{
	int res=0;
	a[200000]=x;
	for (int i=0;i<300;i++) {a[200000]=x-mof[i]; res+=lower_bound(sect[i].begin(),sect[i].end(),200000,cmp)-sect[i].begin();}
	return res;
}
void bs (int l, int r)
{
	if (l>r) return;
	if (l==r) {cout<<l<<endl; return;}
	int mid=(l+r)/2;
	int a=check_smaller(mid),b=check_smaller_or_equal(mid);
//	cout<<l<<' '<<r<<' '<<mid<<' '<<a<<' '<<b<<endl;
	if ((a<=n/2)and(b>n/2)){cout<<mid<<endl; return;}
	else if (a>n/2) bs(l,mid-1);
	else bs(mid+1,r);
}
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   string a,b,c,d;
   cin>>a>>b;
   cin>>n;
   cout<<a<<' '<<b<<endl;
   for (i=1;i<=n;i++)
   {
   	cin>>c>>d;
   	if (c==a) a=d; else b=d;
   	cout<<a<<' '<<b<<endl;
   }
}
/*
HackerEarth Mock Test
*/