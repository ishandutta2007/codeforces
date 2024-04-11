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
	lli n;
	cin>>n;
	if(n<5){
		cout<<n*(n-1)/2;
		return 0;
	}
	int cav = n + n - 1;
	int mx = 1;
	for(int i=1; i<10; i++)
		if(pow(10,i) - 1 <= cav)
			mx = i;
	lli say = pow(10,mx) - 1;
	lli add = pow(10,mx);
	lli sum = 0;
	fori(10){
		lli wh = add * i + say;
		if(wh<=n)
			sum += wh/2;
		else
			sum+=max((lli)0,n-wh/2);
	}
	cout<<sum;
}