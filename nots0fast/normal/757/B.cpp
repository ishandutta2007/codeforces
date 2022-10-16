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
#define MAX 100010
// #define cout out
// #define cin in
lli inf = pow(10,9);
lli modulo = pow(10,9) + 7;
double eps = 1e-12;
ifstream in;
ofstream out;
int main(){
	int sy[MAX] = { };
	int n;
	cin>>n;
	fori(n){
		int ed;
		cin>>ed;
		int kok = sqrt(ed);
		for(int j=2; j<=kok; j++){
			if(!(ed%j)){
				sy[j]++;
				if(ed/j!=j)
					sy[ed/j]++;
			}
		}
		sy[ed]++;
	}
	int mx = 1;
	for(int i=2; i<MAX; i++)
		mx = max(mx,sy[i]);
	cout<<mx;
}