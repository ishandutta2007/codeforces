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
#define MAX 101001
#define MAX1 10000001
int inf = pow(10,9);
int modulo = inf+7;
double eps = 1e-16;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
int main()
{
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	int n,k;
	cin>>n>>k;
	int laz = -2;
	int sum = 0;
	int s1 = 0;
	fori(n){
		int ed;
		cin>>ed;
		sum+=ed;
		int get = min(sum,8);
		s1 += get;
		if(s1>=k && laz==-2)
				laz = i;
		sum-=get;
	}
	cout<<laz+1;
}