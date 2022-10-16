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
#define MAX 2000010
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = pow(10,9)+7;


ll seg[MAX];

// 2*n segtree

void upd(ll idx, ll vl){
	while(idx){
		seg[idx] = max(seg[idx], vl);
		idx/=2;
	}
}

ll que(ll l, ll r){
	ll mx = -inf;
	while(l <= r){
		if(l%2 ==1){
			mx= max(mx, seg[l]);
			++l;
		}
		if(r%2 == 0){
			mx = max(mx, seg[r]);
			--r;
		}
		l/=2;
		r/=2;
	}
	return mx;
}

void deal(){
	ll n;
	cin>>n;
	
	++n;
	
	vector<vector<ll> > arr(n, vector<ll>(2));
	arr[0] = {0, 0};
	
	forj(2){
		for(ll i =1; i<n; i++){
			cin>>arr[i][j];		
		}
	}
	
	stack<pair<ll,ll> > mnIdx;
	
	mnIdx.push(mp(0, 0));
	
	fori(MAX){
		seg[i] = -inf;
	}
	
	upd(n, 0);
	
	for(ll i = 1; i<n; i++){	
		while(arr[i][0] < mnIdx.top().ff){
			mnIdx.pop();
		}
		
		ll pv = mnIdx.top().ss;
		
		ll query = que(n + pv, n + i - 1);
		
//		cout<<"we are querying from "<<mnIdx.top().ss<<" up till "<<i-1<<endl;
		
//		cout<<"answer came up "<<query<<endl;
		
		ll val = query + arr[i][1];
		
		if((ll)mnIdx.size() > 1){
			val = max(val, que(n+pv, n+pv));
		}
		
		upd(n+i, val);
		
//		cout<<"at "<<i<<" answer is "<<query + arr[i][1]<<endl;
		
		mnIdx.push(mp(arr[i][0], i));
	}
	
	ll ans = -inf;
	
	while(mnIdx.size() > 1){
		ll idx = mnIdx.top().ss;
		
		
		ans = max(ans, que(n+idx, n+idx));
		
		mnIdx.pop();
	}
	
	cout<<ans;
	
	
	
	
	
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}