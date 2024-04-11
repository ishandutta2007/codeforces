#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long 
#define double long double
#define MAX 1010
#define MAX2 220
#define pb(a) push_back(a)
double eps = 1e-12;
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;

map<int,int> all;
map<int,int> occ;
void deal(){
	int n;
	cin>>n;
	int mx = 0;
	fori(n){
		int ed;
		cin>>ed;
		if(all[ed])
			occ[all[ed]]--;
		if(occ[all[ed]] == 0)
			occ.erase(all[ed]);
		++all[ed];
		occ[all[ed]]++;
	//	cout<<"we at "<<i<<endl;
		if(occ.size() == 2 ){
			map<int,int> :: iterator it,it1 ;
			it = occ.begin();
			it1 = it;
			++it1;
	//		cout<<(*it).ff<<" "<<(*it).ss<<" "<<(*it1).ff<<" "<<(*it1).ss<<endl;
			if ( ( (*it1).ss == 1 && (*it1).ff == (*it).ff + 1) || ((*it).ff == 1 && (*it).ss == 1) )
				mx = i+1;
		}
		else if (occ.size() == 1 && ((*occ.begin()).ff == 1  || (*occ.begin()).ss == 1) )	
			mx = i+1;
	}
	cout<<mx;
}



int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}