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
 
 
long long t,k,n,m, i,j,jj,mid,a,b,c,res,fail;
vector <long long> cards;
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>n>>k;
   char cc[n][k]; long long val[n];
   for (i=0;i<n;i++)
   {
   	a=0;
   	for (j=0;j<k;j++) {cin>>cc[i][j];a*=3; if (cc[i][j]=='E') a++; else if (cc[i][j]=='T') a+=2; }
	cards.push_back(a); val[i]=a;
   }
   sort (cards.begin(),cards.end());
   j=0;
   
   for (i=0;i<n-1;i++) for (j=i+1;j<n;j++) 
   {
   	a=0;
   	fail=0;
   	for (jj=0;jj<k;jj++) if (cc[i][jj]==cc[j][jj]) {a*=3; 
   	if (cc[i][jj]=='E') a++; else if (cc[i][jj]=='T') a+=2;}
   	else if ((cc[i][jj]=='S')and(cc[j][jj]=='E')) {a*=3; a+=2; }
   	else if ((cc[i][jj]=='E')and(cc[j][jj]=='S')) {a*=3; a+=2;}
   	else if ((cc[i][jj]=='S')and(cc[j][jj]=='T')) {a*=3; a+=1;}
   	else if ((cc[i][jj]=='T')and(cc[j][jj]=='S')) {a*=3; a+=1;}
   	else {a*=3;}
   	//if (!fail) cout<<"pass"<<endl; else continue;
   	b+=upper_bound(cards.begin(),cards.end(),a)-lower_bound(cards.begin(),cards.end(),a);
   	if (val[i]==val[j]) b-=2;
   }
   res+=b/3;
   cout<<res;
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