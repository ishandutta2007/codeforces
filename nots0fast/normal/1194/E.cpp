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
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10,18);
ll modulo = pow(10,9) + 7;
#define MAX (int)(pow(10,4) + 10)

vector<vector<ll> > hor, ver;

ll fen[MAX];
void upd(ll ind, ll vl){
	while(ind < MAX){
		fen[ind]+=vl;
		ind+=ind&-ind;
	}
}
ll que(ll ind){
	ll s = 0;
	while(ind){
		s+=fen[ind];
		ind-=ind&-ind;
	}
	return s;
}
// started 12:23 
bool betw(ll a, ll b, ll c){
	return a <= max(b,c) && a >= min(b,c);
}
void deal(){
	ll n;
	cin>>n;
	fori(n){
		ll x1, x2,  y1, y2;
		cin>>x1>>y1>>x2>>y2;
		x1+=5005, y1+=5005, x2+=5005, y2+=5005;
		if(y1 == y2)
			hor.pb(vector<ll> ({y1, min(x1,x2), max(x1,x2) }));
		else
			ver.pb(vector<ll> ({x1, min(y1,y2) , max(y1,y2) }));
	}
	sort(hor.begin(), hor.end());
	sort(ver.begin(), ver.end());
	ll ans = 0;
	fori(ver.size()){
		deque<pair<ll,ll> > of;
		fori(MAX)
			fen[i] = 0;
		forj(hor.size())
			if(betw(ver[i][0], hor[j][1], hor[j][2]) )
				upd(hor[j][0], 1), of.pb(mp(hor[j][2]+1, hor[j][0]));
		
		sort(of.begin(), of.end());
		for(ll j = i+1; j<ver.size(); j++){
			while(of.size() && of[0].ff <= ver[j][0])
				upd(of[0].ss, -1), of.pop_front();
			ll mn = max(ver[i][1], ver[j][1]);
			ll mx = min(ver[i][2], ver[j][2]);
			if(mx < mn)
				continue;
			ll num = que(mx) - que(mn-1);
//			cout<<"ver "<<i<<" "<<j<<" mn mx : "<<mn<<" "<<mx<<" and the one "<<num<<endl;
			ans += num*(num-1)/2;
		}
	}
	cout<<ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}