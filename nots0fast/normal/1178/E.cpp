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
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = 998244353 ;
#define MAX (int)(pow(10,6)+ 10)

deque<ll> occur[3];
ll edg[MAX];
ll ans[MAX];
ll sec[MAX];

void deal(){
	string a;
	cin>>a;
	ll n = a.length();
	ll fr = 0, bc = n-1;
	vector<pair<ll,ll> > ans;
	while(fr<=bc){
		if(a[bc] == a[fr]){
			ans.pb(mp(fr, bc));
			++fr, --bc;
		}
		else if(a[fr] == a[bc-1]){
			ans.pb(mp(fr, bc-1));
			++fr;
			--bc;
			--bc;
		}
		else if(a[fr+1] == a[bc]){
			ans.pb(mp(fr+1, bc));
			fr+=2;
			--bc;
		}
		else{
			ans.pb(mp(fr+1, bc-1));
			fr+=2;
			bc-=2;
		}
	} 
	reverse(ans.begin(), ans.end());
	deque<char> fin;
	for(auto el : ans){
		if(el.ff == el.ss)
			fin.pb(a[el.ff]);
		else
			fin.push_front(a[el.ff]), fin.push_back(a[el.ff]);
	}
	assert(fin.size() >= a.length()/2);
	for(auto f:fin)
		cout<<f;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}

/*

4 6
4 8 7 8
1 2 4
2 1 2 2
1 3 4
2 1 1 8
1 1 3
1 1 4

acacabbbbbbbacc

cccbbbaaa
*/