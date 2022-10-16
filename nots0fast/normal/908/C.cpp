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
double eps = 1e-12;
ifstream in;
ofstream out;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
double r;
bool intersect(double x1, double y1, double x2, double y2){
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) <= 4* r*r ;
}
int main(){
	int n;
	cin>>n>>r;
	double xs[n];
	fori(n)
		cin>>xs[i];
	double hs[n];
	fori(n){
		double mx = r;
		forj(i){
			if(!intersect(xs[i],hs[j],xs[j],hs[j]))
				continue;
			double a = hs[j], b = pow(10,8);
			while((b-a)>eps){
				double c = (a+b)/2;
				if(!intersect(xs[i],c,xs[j],hs[j]))
					b=c;
				else
					a=c;
			}
			mx = max(mx,a);
		}
		hs[i] = mx;
		cout<<setp<<hs[i]<<' ';
	}
}