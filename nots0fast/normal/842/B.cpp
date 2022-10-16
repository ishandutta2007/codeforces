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
	int d,r;
	int n;
	cin>>r>>d>>n;
	r-=d;
	int p[n][3];
	int say = n;
	fori(n){
		forj(3)
			cin>>p[i][j];
		int dist = p[i][0]*p[i][0] + p[i][1]*p[i][1] ;
		if(dist<(r+p[i][2])*(r+p[i][2]) || dist>(r+d-p[i][2])*(r+d-p[i][2]))
			--say;
	}
	cout<<say;
}