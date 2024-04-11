#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(12)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define lli long long int
#define double long double
#define MAX 300001
int inf = pow(10,9);
int modulo = 20011;
double eps = 1e-16;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string el = "^>v<";
	char a,b;
	cin>>a>>b;
	int n;
	cin>>n;
	if(!(n%2))
		cout<<"undefined";
	else{
		n%=4;
		int z = el.find(a);
		int k = el.find(b);
		if((k-z+4) % 4 == n)
			cout<<"cw";
		else
			cout<<"ccw";
	}
}