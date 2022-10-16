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
#define MAX (int)(pow(10,6)+10)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,7)+10;
ll modulo = 998244353;

vector<vector<ll> > all;
ll ans[MAX];


void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		all.clear();
		fori(n){
			ll a , b;
			cin>>a>>b;
			vector<ll> th (3, 0);
			th[0] = a, th[1] = b, th[2] =  i;
			all.pb(th);
		}
		sort(all.begin(), all.end());
		ll lst[2] = {-1, -1};
		ll kd = 0;
		fori(n){
			if(all[i][0] > lst[kd])
				kd^=1;
			ans[all[i][2]] = kd;
			lst[kd] = max(lst[kd], all[i][1]);
		}
		bool ok[2] ={0,0};
		fori(n)
			ok[ans[i]] |= 1;
		if(!ok[0] || !ok[1]){
			cout<<-1<<'\n';
			continue;
		}
		fori(n)
			cout<<ans[i]+1<<' ';
		cout<<'\n';
	}
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