#include <bits/stdc++.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
 
#define mp make_pair
#define pb push_back
#define INF 1000000000
 
typedef long long ll;
typedef pair<int,int> pii;
const double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	map<int,string> mapa;
	mapa[12] = "x^y^z";
	mapa[11] = "x^z^y";
	mapa[10] = "(x^y)^z";
	mapa[9] = "(x^z)^y";
	mapa[8] = "y^x^z";
	mapa[7] = "y^z^x";
	mapa[6] = "(y^x)^z";
	mapa[5] = "(y^z)^x";
	mapa[4] = "z^x^y";
	mapa[3] = "z^y^x";
	mapa[2] = "(z^x)^y";
	mapa[1] = "(z^y)^x";
	vector<pair<long double,int>> vp;
	long double x,y,z;
	cin >> x >> y >> z;
	vp.pb(mp(log(x)*pow(y,z),12));
	vp.pb(mp(log(x)*pow(z,y),11));
	vp.pb(mp(log(x)*y*z,10));
	vp.pb(mp(-INF,9));
	vp.pb(mp(log(y)*pow(x,z),8));
	vp.pb(mp(log(y)*pow(z,x),7));
	vp.pb(mp(log(y)*x*z,6));
	vp.pb(mp(-INF,5));
	vp.pb(mp(log(z)*pow(x,y),4));
	vp.pb(mp(log(z)*pow(y,x),3));
	vp.pb(mp(log(z)*x*y,2));
	vp.pb(mp(-INF,1));
	sort(vp.begin(),vp.end());
 
	cout << mapa[vp[11].second] << endl;
}