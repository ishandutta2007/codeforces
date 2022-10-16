#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(6)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define lli long long int
#define double long double
#define MAX 100002
int inf = pow(10,9);
lli modulo = inf+7;
double eps = 1e-9;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	if(n==1){
		cout<<2<<'\n';
		cout<<"1 1";
		return 0;
	}
	cout<<(3*n)/2<<'\n';
	for(int i=2; i<=n; i+=2)
		cout<<i<<' ';
	for(int i=1; i<=n; i+=2)
		cout<<i<<' ';
	for(int i=2; i<=n; i+=2)
		cout<<i<<' ';
}