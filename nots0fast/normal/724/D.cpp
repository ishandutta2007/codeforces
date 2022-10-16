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
#define MAX (int)(pow(10,5) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;

set<ll> all[26];

void deal(){
	forj(26)
		all[j].insert(MAX);
	ll m;
	cin>>m;
	string s;
	cin>>s;
	fori((ll)s.length())
		all[s[i]-'a'].insert(i);
	string ans = "";
	ll rig = m;
	while(rig <= s.length()){
		forj(26){
				auto  it = all[j].lower_bound(rig);
				if( it != all[j].begin() ){
					--it;
					if( *it >= rig-m ){
						ans+= (char)('a'+j);
						rig = (*it) + 1 + m;
 						break;
					}
				}
		}
		
	}
	sort(ans.begin(), ans.end());
	int lz = ans[ans.length()-1] - 'a';
	int sy = 0;
	fork(ans.length())
		if(ans[k]-'a' == lz){
			++sy;
		}
	string act = "";
	fori(s.length())
		if(s[i] - 'a' < lz)
			act+=s[i];
	forj(sy)
		act+='a'+lz;
	sort(act.begin(), act.end());
	cout<<act;
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