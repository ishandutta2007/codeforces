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
lli inf = pow(10,16);
int modulo = pow(10,9)+7;
double eps = 1e-15;
ifstream in;
ofstream out;
void deal(){
	int n;
	cin>>n;
	map<int,int> pl1;
	int ed;
	fori(n)
		cin>>ed, pl1[ed] = i;
	map<int,int> :: iterator it,it1;
	map<int,int> pl2;
	fori(2*n){
		char f;
		cin>>f;
		int z = f-'0';
		if(z){
			it = pl2.end();
			--it;
			cout<<(*it).ss+1<<' ';
			pl2.erase(it);
		}
		else{
			it = pl1.begin();
			cout<<(*it).ss+1<<' ';
			pl2[(*it).ff] = (*it).ss;
			pl1.erase(it);
		}
	}
}
int main() {
    deal();
}