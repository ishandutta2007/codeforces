#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(12)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define lli long long int
#define double long double
#define MAX 100001
#define cut 701
//#define M_PI 2*acos(0)
lli inf = pow(10,18);
int modulo = inf+7;
double eps = 1e-16;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
int main()
{
	lli l,r,k,x,y;
	cin>>l>>r>>x>>y>>k;
	lli z1 = x*k, z2 = y*k;
	while(x<y){
		lli c = (x+y)/2+1;
		if(c*k>r)
			y=c-1;
		else
			x=c;
	}
	if(x*k<=r && x*k>=l)
		cout<<"YES";
	else
		cout<<"NO";
}