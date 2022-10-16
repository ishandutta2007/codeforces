#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define ll long long 
#define MAX (int)(pow(10,6)+ 10)
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10,18);
ll modulo = 1000007;
double eps = 1e-6;
ifstream in;
ofstream out;

vector<ll> dv[MAX];
bool pr[MAX];

void pre(){
	for(ll i= 2; i<MAX; i++){
		pr[i] = 1;
	}
	for(ll i = 2; i<MAX; i++){
		if(pr[i]){
			dv[i].pb(i);
			for(ll j = 2*i ; j<MAX; j+=i){
				pr[j] = 0;
				dv[j].pb(i);
			}
		}
	}	
}
	

void deal(){
	pre();
	ll t;
	cin>>t;
	forl(t){
		map<ll, ll> all;
		ll n;
		cin>>n;
		fori(n){
			ll ai;
			cin>>ai;
			ll ilk = ai;
			for(auto& el : dv[ilk]){
				while(ai % (el*el) == 0){
					ai/=(el*el);
				}
			}
			all[ai]++;
		}
		ll mx1 = 0;
		for(auto& el : all){
			mx1 = max(mx1, el.ss);
		}
		map<ll,ll> all2;
		for(auto& el: all){
			if(el.ss % 2 == 0){
				all2[1]+=el.ss;
			}
			else{
				all2[el.ff]+=el.ss;
			}
		}
		ll mx2 = 0;
		for(auto& el2 : all2){
			mx2 = max(mx2, el2.ss);
		}
		
		ll q;
		cin>>q;
		forl(q){
			ll wi;
			cin>>wi;
			if(wi == 0){
				cout<<mx1<<'\n';
			}
			else{
				cout<<mx2<<'\n';
			}
		}
	}
	
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
//	test();
	deal();
}



/* 
6 8 
1 2
2 3
3 4
4 1
2 5
3 5
1 6
4 6
*/