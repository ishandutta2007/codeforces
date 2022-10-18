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
#define MAX 100100
#define ch 201
#define double long double
int inf = pow(10,9);
int modulo = pow(10,9)+7;
double eps = 1e-12;
ifstream in;
ofstream out;
vector<int> g[MAX];
void deal(){
	int n;
	cin>>n;
	fori(n-1){
		int a,b;
		cin>>a>>b; --a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int seen = -1;
	vector<int> zero;
	fori(n){
		if(g[i].size()>2){
			if(seen!=-1){
				cout<<"No";
				return;
			}
			seen = i;
		}
		else if(g[i].size()==1)
			zero.push_back(i);
	}
	if(seen==-1){
		cout<<"Yes\n";
		cout<<1<<'\n';
		cout<<zero[0]+1<<" "<<zero[1]+1<<'\n';
	}
	else{
		cout<<"Yes\n";
		cout<<zero.size()<<'\n';
		fori(zero.size())
			cout<<seen+1<<" "<<zero[i]+1<<'\n';
	}
}
int main() {
    deal();
}