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
#define MAX 10002
int inf = pow(10,9);
lli modulo = inf+7;
double eps = 1e-9;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
int main()
{
	string a;
	cin>>a;
	int n;
	cin>>n;
	bool bir = 0, iki = 0;
	fori(n){
		string z;
		cin>>z;
		if(z[1]==a[0])
			bir = 1;
		if(z[0]==a[1])
			iki = 1;
		if(z==a){
			cout<<"YES";
			return 0;
		}
	}
	if(bir && iki)
		cout<<"YES";
	else
		cout<<"NO";
}