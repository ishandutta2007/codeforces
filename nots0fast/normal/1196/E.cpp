
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
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,8);
ll modulo = pow(10,9)+7  ;
#define ld long double
#define MAX (int)(pow(10,6)+ 10)

ll dx[4] = {-1, 1, 0 ,0 };
ll dy[4] = { 0, 0,-1, 1};


void deal(){
	ll q;
	cin>>q;
	forl(q){
		ll lz[2];
		forj(2)
			cin>>lz[j];
		swap(lz[0], lz[1]);
		ll wh = 0;
		pair<ll,ll> st = mp(pow(10,8), pow(10,8));
		if(lz[1] < lz[0])	
			--st.ff, wh = 1;
		vector<pair<ll,ll> > ans;
		st.ff--;
		ans.pb(st);
		--lz[!wh];
		st.ff++;
		while(lz[wh]){
			ans.pb(st);
			--lz[wh];
			st.ff++;
			if(lz[!wh])
				ans.pb(st), --lz[!wh];
			st.ff++;
		}
		ll sv = ans.size();
		for(ll i = 1; i<sv; i+=2){
			pair<ll,ll> cur = ans[i];
			if(lz[!wh]){
				cur.ss--, ans.pb(cur);
				--lz[!wh];
				if(lz[!wh])
					cur.ss+=2, ans.pb(cur), --lz[!wh];
			}
		}
		if(!lz[0] && !lz[1]){
			cout<<"YES\n";
			for(auto el : ans)
				cout<<el.ff<<' '<<el.ss<<'\n';
		}
		else
			cout<<"NO\n";
	}
}
 
int main(){
//	cin.tie(0);
//	ios_base::sync_with_stdio(0);
	deal();
}
 
/*
 
5 1
1 2 3 4 5


*/