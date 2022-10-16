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
#define ch 2000
#define nm 50
int inf = pow(10,9);
lli modulo = inf;
double eps = 1e-10;
ifstream in;
ofstream out;
int main(){
	int n;
	cin>>n;
	int sy[2] = { };
	fori(n){
		int ed;
		cin>>ed;
		sy[ed&1]++;
	}
	int say = min(sy[0] , sy[1]);
	sy[1] -= say;
	cout<<say + sy[1]/3;
}