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
#define lli long long int
#define double long double
#define MAX 200001
int inf = pow(10,9);
lli modulo = inf+7;
double eps = 1e-10;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
lli x,k;
lli nm(lli a){
	lli sy = 0;
	while(!(a%10))
		++sy, a/=10;
	return sy;
}
lli solve(){
	while(1){
		if(nm(x)>=k)
			return x;
		if(nm(x*2)>nm(x))
			x*=2;
		else if(nm(x*5)>nm(x))
			x*=5;
		else
			x*=10;
	}
}
int main(){
	cin>>x>>k;
	cout<<solve();
}