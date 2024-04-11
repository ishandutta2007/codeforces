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
#define MAX 26
#define N 100000
// #define cout out
// #define cin in
lli inf = pow(10,9);
lli modulo = inf+ 7;
double eps = 1e-10;
ifstream in;
ofstream out;
int main(){
	string check = "aeiou13579";
	string a;
	cin>>a;
	int sy = 0;
	fori(a.length())
		if(check.find(a[i])!=string :: npos)
			++sy;
	cout<<sy;
}