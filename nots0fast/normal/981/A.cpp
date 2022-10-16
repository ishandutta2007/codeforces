#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(x) setprecision(x)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<v; i++)
#define forj(v) for(lli j=0; j<v; j++)
#define fork(v) for(lli k=0; k<v; k++)
#define forl(v) for(lli l=0; l<v; l++)
#define fort(v) for(lli t=0; t<v; t++)
#define forz(v) for(lli z=0; z<v; z++)
#define forx(v) for(lli x=0; x<v; x++)
#define lli long long int
#define MAX 200100
#define ch 201
#define double long double
int inf = pow(10,9);
int modulo = pow(10,9)+7;
double eps = 1e-12;
ifstream in;
ofstream out;
void deal(){
	int mx =  0;
	string a;
	cin>>a;
	fori(a.length()){
		string b = "";
		for(int j=i; j<a.length(); j++)
			b+=a[j];
		string z = b;
		reverse(z.begin(),z.end());
		if(z!=b)
			mx = max(mx,(int)b.length());
	}
	cout<<mx;
}
int main() {
    deal();
}