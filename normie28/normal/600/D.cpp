 #include <bits/stdc++.h>
using namespace std;
 #define MOD 1000003
 #define A '@'
 #define B '*'
 #define C '#'
 #define max(a,b) ((a>b)?a:b)
 #define min(a,b) ((a<b)?a:b)
 #define endl "\n"
 #define PI 3.14159265359
// #define int int64_t
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
 
int t,k,n,m, i,j,jj,mid,a,b,c,d,e,f,g,root,ok[10][11],pol[10];
vector <int> lis,lis2;
void ans (long double x)
{
	cout<<fixed<<setprecision(8)<<x;
	exit(0);
}
int main()
{
	long double x1,y1,r1,x2,y2,r2,d,area,p,arc1,arc2;
	cin>>x1>>y1>>r1>>x2>>y2>>r2;
	d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	if (d+r1<=r2) ans(PI*r1*r1);
	if (d+r2<=r1) ans(PI*r2*r2);
	if (d>=r1+r2) ans(0);
	p=(d+r1+r2)/2;
//	cout<<d<<' '<<r1<<' '<<r2<<endl;
	area=sqrt(p*(p-d)*(p-r1)*(p-r2));
//	cout<<area<<endl;
	arc1=asin(area*2/d/r1);
	if ((r2)*(r2)-d*d>r1*r1) arc1=PI-arc1;
	arc1*=r1*r1;
	arc2=asin(area*2/d/r2);
	if ((r1)*(r1)-d*d>r2*r2) arc2=PI-arc2;
	arc2*=r2*r2;
//	cout<<arc1<<' '<<arc2<<' '<<area<<' ';
	ans(arc1+arc2-2*area);
	
}