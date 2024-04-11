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
#define MAX 100020
#define pb(a) push_back(a)
// #define cout out
// #define cin in
lli inf = pow(10,9);
lli modulo = inf+7;
double eps = 1e-10;
ifstream in;
ofstream out;
void deal(){
	int w1,h1,w2,h2;
	cin>>w1>>h1>>w2>>h2;
	cout<<(h2*2 + w2+2 + (w1-w2) + h1*2 + w1+2); 
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}