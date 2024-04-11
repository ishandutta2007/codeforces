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
#define MAX 1510
#define ch 51
#define double long double
int inf = pow(10,9);
int modulo = pow(10,9)+7;
double eps = 1e-15;
ifstream in;
ofstream out;
lli gcd(lli a,lli b){
	return !b ? a : gcd(b,a%b);
}
void deal(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	fori(n){
		lli p,q,b;
		cin>>p>>q>>b;
		lli ebob = gcd(p,q);
		p/=ebob;
		q/=ebob;
		lli md = p%q;
		ebob = gcd(q,b);
		while(ebob!=1){
			q/=ebob;
			ebob = gcd(ebob,q);
		}
		if(md==0 || q==1)
			cout<<"Finite\n";
		else
			cout<<"Infinite\n";
	}
}
int main() {
//	while(1)
    deal();
}