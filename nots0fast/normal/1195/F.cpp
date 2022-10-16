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
#define MAX 300100
 
ll fen[MAX];
void upd(ll ind, ll vl){
	while(ind <MAX){
		fen[ind ] += vl;
		ind+=ind&-ind;
	}
}
ll quer(ll ind){
	ll s = 0;
	while(ind){
		s += fen[ind];
		ind -=ind&-ind;
	}
	return s;
}
void handle(ll& dx, ll& dy){
	if(dx && dy){
		ll ebob = __gcd((ll)fabs(dx), (ll)fabs(dy));
		dx /= ebob, dy/=ebob;
	}
	if(!dx)
		dy = dy/fabs(dy) * inf;
	else if(!dy)
		dx = dx/ fabs(dx) * inf;
}
map<ll, map<ll,deque<ll> > > when;
ll arr[MAX][2];
vector<pair<ll,ll> > sv[MAX];
void deal(){
	ll n;
	cin>>n;
	fori(n){
		ll k;
		cin>>k;
		
		fori(k)
			forj(2)
				cin>>arr[i][j];
		forj(k){
			ll nxt = (j+1)%k;
			ll dx = arr[nxt][0] - arr[j][0];
			ll dy = arr[nxt][1] - arr[j][1];
			handle(dx, dy);
			when[dx][dy].push_back(i+1);
			sv[i+1].pb(mp(dx,dy));
		}
	}
	ll q;
	cin>>q;
	vector<vector<ll> > que(q);
	vector<ll> ans(q);
	fori(q){
		ll a,b;
		cin>>a>>b;
		que[i] = vector<ll> ({a,b, i});
	}
	sort(que.begin(), que.end());
	for(auto mp : when)
		for(auto cur : mp.ss){
			upd(cur.ss[0], 1);
		}
	ll st = 1;
	fori(que.size()){
		while(st<que[i][0]){
			for(auto el : sv[st]){
				upd(when[el.ff][el.ss][0], -1);
				when[el.ff][el.ss].pop_front();
				if(when[el.ff][el.ss].size()){
					upd(when[el.ff][el.ss][0], 1);
				}
			}
			++st;
		}
		ans[que[i][2]] = quer(que[i][1]);
	}
	fori(q)
		cout<<ans[i]<<'\n';
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}