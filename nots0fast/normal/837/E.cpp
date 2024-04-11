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
lli inf = pow(10,15);
int modulo = 20011;
double eps = 1e-16;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
lli gcd(lli a, lli b){
	return !b ? a : gcd(b,a%b);
}
int main()
{
	lli a, b;
	cin>>a>>b;
	lli kok = sqrt(a);
	set<lli> divs;
	for(lli i=1; i<=kok; i++){
		if(!(a%i))
			divs.insert(i), divs.insert(a/i);
	}
	map<lli,vector<lli> > div;
	set<lli> :: iterator it = divs.begin();
	while(it!=divs.end()){
		set<lli> :: iterator it1 = it;
		++it1;
		while(it1!=divs.end()){
			if(!(*it1 % *it))
				div[*it].push_back(*it1);
			++it1;
		}
//		cout<<*it<<endl;
//		fori(div[*it].size())
//			cout<<div[*it][i]<<endl;
		++it;
	}
	lli ebob = gcd(a,b);
	lli cem = 0;
	while(b){
//		cout<<a<<' '<<b<<' '<<ebob<<'\n';
		lli laz = -1, minn = inf;
		fori(div[ebob].size()){
//			cout<<div[ebob][i]<<endl;
			lli qal = b % div[ebob][i];
			lli nece = qal/ebob;
			if(nece<minn)
				laz = div[ebob][i], minn =nece;
		}
		if(laz==-1){
			cem+=b/ebob;
			b = 0;
		}
		else{
			lli qal = b % laz;
			lli nece = qal/ebob;
			b-=nece*ebob;
			ebob = laz;
			cem+=nece;
		}
	}
	cout<<cem;
}