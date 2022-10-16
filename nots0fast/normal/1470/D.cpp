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




vector<ll> g[MAX];

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n , m;
		cin>>n>>m;
		
		
		vector<bool> marked(n+1, 0);
		
		
		fori(n+10){
			g[i].clear();
		}
		
		fori(m){
			ll ai, bi;
			cin>>ai>>bi;
			g[ai].pb(bi);
			g[bi].pb(ai);
		}
		
		set<ll> possible;
		set<ll> used;
		
		possible.insert(1);
		while(possible.size()){
			auto hd = *possible.begin();
			possible.erase(possible.begin());
			marked[hd] = 1;
			used.insert(hd);
			for(auto& hr :g[hd]){
				if(used.find(hr) == used.end()){
					used.insert(hr);
					if(possible.find(hr)!=possible.end()){
						possible.erase(hr);
					}
					for(auto el : g[hr]){
						if(used.find(el) == used.end()){
							possible.insert(el);
						}
					}
				}
			}
		}
		
		
		if(used.size()!=n){
			cout<<"NO\n";
			continue;
		}
		
		
		vector<ll> all;
		for(ll i=  1; i<=n; i++){
			if(marked[i]){
				all.pb(i);
			}
		}
		
		cout<<"YES\n"<<all.size()<<'\n';
		for(auto& el : all){
			cout<<el<<' ';
		}
		cout<<'\n';
		
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