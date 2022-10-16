#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(x) setprecision(x)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define lli  long long int
#define MAX 51
#define ch 300
#define double long double
lli inf = pow(10,18);
unsigned lli modulo = pow(10,9)+7;
double eps = 1e-7;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
void deal(){
//	cin.tie(0);
//	ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	map<lli,lli> nodes[n]; // first length so far, second biggest dude
	fori(n)
		nodes[i][-inf] = 0;
	fori(m){
		int a,b,w;
		cin>>a>>b>>w; --a, --b;
		map<lli,lli> :: iterator it2,it1,it = nodes[a].find(w);
		if(it== nodes[a].end()){
			nodes[a][w] = 0;
			it = nodes[a].find(w);
			it1 = it;
			--it;
			nodes[a].erase(it1);
		}
		else
			--it;
		int sy = (*it).ss +1;
		int ed = nodes[b][w];
		if(sy > ed)
			nodes[b][w] = sy;
		it = nodes[b].find(w);
		it1 = it; ++it1;
		while(it1!=nodes[b].end()){
			it2 = it1, ++it2;
			if((*it).ss > (*it1).ss)
				nodes[b].erase(it1);
			else
				break;
			it1 = it2;
		}
		it1 = it;
		--it1;
		if((*it1).ss >= (*it).ss)
			nodes[b].erase(it);
	}
	lli mx = 0;
	fori(n){
		map<lli,lli> :: iterator it = nodes[i].end();
		--it;
		mx = max(mx,(*it).ss);
	}
	cout<<mx;
}
int main() {
//	map<int,int> aaa;
//	aaa[1] = 2;
//	aaa.insert(mp(1,3));
//	cout<<aaa[1]<<endl;
	deal();
}