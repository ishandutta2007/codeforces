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
#define MAX 1000001
int inf = pow(10,9);
int modulo = 20011;
double eps = 1e-16;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	vector<pair<int,int> > xam;
	fori(n){
		int x,y;
		cin>>x>>y;
		xam.push_back(mp(x,y));
		xam.push_back(mp(y,x));
	}
	int maxx = 0;
	fori(xam.size())
		for(int j=i+1; j<xam.size(); j++){
			if(!(i%2)&& j==i+1)
				continue;
	//		cout<<xam[i].ff<<' '<<xam[i].ss<<' '<<xam[j].ff<<' '<<xam[j].ss<<endl;
			if( (xam[i].ff+xam[j].ff<=a && max(xam[i].ss,xam[j].ss)<=b)  )
				maxx = max(maxx,xam[i].ff*xam[i].ss+xam[j].ff*xam[j].ss);
		}
	int tm = a; a=b,b=tm;
	fori(xam.size())
		for(int j=i+1; j<xam.size(); j++){
			if(!(i%2)&& j==i+1)
				continue;
	//		cout<<xam[i].ff<<' '<<xam[i].ss<<' '<<xam[j].ff<<' '<<xam[j].ss<<endl;
			if( (xam[i].ff+xam[j].ff<=a && max(xam[i].ss,xam[j].ss)<=b)  )
				maxx = max(maxx,xam[i].ff*xam[i].ss+xam[j].ff*xam[j].ss);
		}
	cout<<maxx;
}