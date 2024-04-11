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
	vector<lli> a[2];
	lli s[2] = { };
	lli n;
	cin>>n;
	for(lli i=1; i<n+1; i++)
		a[i&1].push_back(i), s[i&1]+=i;
	if(s[1]>s[0]){
		fori(a[0].size())
			if(s[1]>s[0]){
				lli tm = a[1][a[1].size()-1-i];
				a[1][a[1].size()-1-i] = a[0][a[0].size()-1-i] ,a[0][a[0].size()-1-i] = tm; 
				--s[1];
				++s[0];
			}
	}
	else{
		fori(a[0].size())
			if(s[0]>s[1]){
				lli tm = a[1][i];
				a[1][i] = a[0][i], a[0][i] = tm;
				--s[0];
				++s[1];
			}
	}
	cout<<fabs(s[0]-s[1])<<'\n';
	cout<<a[0].size()<<' ';
	fori(a[0].size())
		cout<<a[0][i]<<' ';
}