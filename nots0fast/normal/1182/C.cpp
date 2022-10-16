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
#define ld long double
#define pb(a) push_back(a)
#define MAX (int)(pow(10,3) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18)+10;
ll modulo = 10056;



map<ll, map<ll, vector<string> > > all;
string vowel = "aioue";
stack<string> g[2];
vector<string> ans;


void deal(){
	ll n;
	cin>>n;
	fori(n){
		string a;
		cin>>a;
		ll sy = 0 , lz;
		for(char i : a)
			if(vowel.find(i) != string::npos)
				++sy, lz = vowel.find(i);
		all[sy][lz].pb(a);
	}
	
	for(auto lz : all){
		vector<string> yen;
		for(auto lz1 : lz.ss){
			ll bound = lz1.ss.size();
			if(bound&1){
				yen.pb(lz1.ss[bound-1]);
				--bound;
			}
			forj(bound)
				g[0].push(lz1.ss[j]);
		}
		ll bound = yen.size();
		if(bound&1)
			--bound;
		forj(bound)
			g[1].push(yen[j]);
	}

	while(g[0].size()>1 && g[1].size()>1){	
		string yen = g[1].top() + " " + g[0].top();
		fori(2)
			g[i].pop();
		ans.pb(yen);
		yen = g[1].top() + " " + g[0].top();
		fori(2)
			g[i].pop();
		ans.pb(yen);
	}
	while(g[0].size()>3){
		string yen = g[0].top() + " ";
		g[0].pop(); 
		string yen1 = g[0].top() + " ";
		g[0].pop();
		yen += g[0].top();
		g[0].pop(); 
		yen1 += g[0].top();
		g[0].pop();
		ans.pb(yen);
		ans.pb(yen1);
	}
	cout<<ans.size()/2<<'\n';
	for(auto str : ans)
		cout<<str<<'\n';
}




int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}





// 4 1 1000 10
// 1 2 1
// ? 1 2
// ? 2 1
// + 2 4 1
// ? 1 4
// ? 4 1
// ? 4 2
// + 3 4 1
// ? 1 3
// ? 3 1