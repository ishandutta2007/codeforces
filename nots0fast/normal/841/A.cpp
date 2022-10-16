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
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,k;
	cin>>n>>k;
	set<char> xam[k];
	bool al = 1;
	fori(n){
		char f;
		cin>>f;
		int laz = -1;
		fori(k)
			if(xam[i].find(f)==xam[i].end())
				laz = i;
		if(laz==-1)
			al = 0;
		else
			xam[laz].insert(f);
	}
	if(al)
		cout<<"YES";
	else
		cout<<"NO";
}