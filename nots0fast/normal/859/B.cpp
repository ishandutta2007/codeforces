#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(10)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define ll long long int
#define double long double
#define N 4000
#define M 10000
int inf = pow(10,9);
int modulo = inf+7;
double eps = 1e-10;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int main()
{
	int n;
	cin>>n;
	int ed = sqrt(n);
	int ff = n-ed*ed;
	int norm = ed*4;
	if(ff){
		if(ff<ed+1)
			norm+=2;
		else if(ff<2*ed+1)
			norm+=4;
		else if(ff<3*ed+1)
			norm+=6;
		else
			norm+=8;		
	}
	cout<<norm;
	
}