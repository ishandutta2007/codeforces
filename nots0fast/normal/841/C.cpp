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
#define lli long long int
#define double long double
#define MAX 100001
#define sz 300
int inf = pow(10,9);
int modulo = inf+7;
double eps = 1e-16;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
bool J(pair<int,int> a, pair<int,int> b){
	return a.ff < b.ff;
}
bool J1(pair<int,int> a, pair<int,int> b){
	return a.ff > b.ff;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int m;
	cin>>m;
	int cons[m];
	pair<int,int> a[2][m];
	forj(2)
		fori(m){
			a[j][i].ss = i;
			cin>>a[j][i].ff;
		}
	sort(a[0],a[0]+m,J1);
	sort(a[1],a[1]+m,J);
	fori(m){
		cons[a[1][i].ss] = a[0][i].ff;
	}
	fori(m)
		cout<<cons[i]<<' ';
}