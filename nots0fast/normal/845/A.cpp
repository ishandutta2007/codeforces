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
int MAX  =  100;
int inf = pow(10,9);
int modulo = inf+7;
double eps = 1e-16;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
int main()
{
	int n;
	cin>>n;
	vector<int> xam(2*n+1);
	xam[0] = -1;
	fori(2*n)
		cin>>xam[i+1];
	sort(xam.begin(),xam.end());
	if(xam[n]==xam[n+1])
		cout<<"NO";
	else
		cout<<"YES";
}