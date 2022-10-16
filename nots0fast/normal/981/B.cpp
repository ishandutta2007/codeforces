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
bool J(pair<int,int> &a,pair<int,int> &b){
	return a.ss > b.ss;
}
void deal(){
	set<int> taken;
	int n;
	cin>>n;
	vector<pair<int,int> > all;
	fori(n){
		int a,x;
		cin>>a>>x;
		all.push_back(mp(a,x));
	}
	cin>>n;
	fori(n){
		int a,x;
		cin>>a>>x;
		all.push_back(mp(a,x));
	}
	sort(all.begin(),all.end(),J);
	lli s = 0;
	fori(all.size()){
		if(taken.find(all[i].ff) == taken.end())
			taken.insert(all[i].ff), s+=all[i].ss;
	}
	cout<<s;
}
int main() {
    deal();
}