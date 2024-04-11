#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
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
#define MAX (int)(pow(10,6) + 10)
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9)+7;

void lookForK(ll k, vector<vector<ll> >& taken, vector<vector<ll> >& should,ll& x, ll& y, ll& n){
	fori(n){
		forj(n){
			if(should[i][j] == k && taken[i][j] == 0){
				x = i, y = j;
				return;
			}
		}
	}
}


void deal(){
	ll n;
	cin>>n;
	vector<vector<ll> > taken(n, vector<ll>(n, 0));
	vector<vector<ll> > should(n, vector<ll>(n, 0));
	
	fori(n){
		forj(n){
			should[i][j] = ((i+j)%2)  + 1;
		}
	}
	
	ll last;
	
	ll turns = 0;
	
	while(turns < n*n){
		cin>>last;
		ll x = -1, y = -1;
		ll k = -1;
		
		if(last!=1){
			k = 1;
			lookForK(1, taken, should, x, y, n );
		}
		else{
			k = 2;
			lookForK(2, taken, should, x, y, n);
		}
		if(x == -1){
			break;
		}
		taken[x][y] = 1;
		cout<<k<<" "<<x+1<<" "<<y+1<<endl;
		++turns;
	}
	
	while(turns < n*n){
		for(ll j = 1; j<=2; j++){
			ll x = -1, y = -1, k = j;
			lookForK(k, taken, should, x, y, n);
			if(x != -1){
				taken[x][y] = 1;
				if(last!=3){
					cout<<3<<" "<<x+1<<" "<<y+1<<endl;
				}
				else{
					cout<<j<<" "<<x+1<<" "<<y+1<<endl;
				}
			}
		}
		
		++turns;
		
		if(turns < n*n){
			cin>>last;
		}
	}
	
	
	
	
	
	
	
}


 
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}