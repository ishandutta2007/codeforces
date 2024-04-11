/*
#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
*/

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
#define mt make_tuple
const ll INF = 0x3f3f3f3f;
const ll inf =  1e18;
const ll modulo = pow(10, 9) + 7;

#define MAX 1'000'010

ll mn[MAX];
ll lz[MAX];

void pull(ll hd){
	mn[hd] = min(mn[hd<<1], mn[(hd<<1)|1]);
}

void push(ll hd, ll l, ll r){
	mn[hd] += lz[hd];
	if(l!=r){
		lz[hd<<1] += lz[hd];
		lz[(hd<<1)|1] += lz[hd];
	}
	lz[hd] = 0;
}

void upd(ll hd, ll l, ll r, ll ql, ll qr, ll vl){
	if(lz[hd]){
		push(hd, l, r);
	}
	if(r < ql || qr < l){
		return;
	}
	if(ql <= l && r <= qr){
		lz[hd] += vl;
		push(hd, l, r);
		return;
	}
	upd(hd*2, l, (l+r)/2, ql, qr, vl);
	upd(hd*2+1, (l+r)/2+1, r, ql, qr, vl);
	pull(hd);
}

ll findte(ll s, ll n, vector<ll>& arr){
	// find first index of suitable teacher
	ll lo = 0, hi = arr.size()-1;
	while(lo < hi){
		ll mid = (lo+hi)/2;
		// arr[mid] >= s/n
		if(arr[mid] * n >= s ){
			hi = mid;
		}
		else{
			lo = mid+1;
		}
	}
	return lo;
}

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n, m;
		cin>>n>>m;
		// min  segtree on teacher count , n teachers
		
		// store (number of teachers - number of groups needing it)
		vector<ll> arr(n+1);
		fori(n){
			cin>>arr[i];
		}
		arr[n] = (1e9);
		sort(arr.begin(), arr.end());
		fori(4*n + 100){
			lz[i] = 0;
			mn[i] = 0;
		}
		// initialize counts
		
		// root node is  [0 .... n]
		
		for(ll i = n-1; i>=0; i--){
			upd(1, 0, n, 0, i, 1);
		}
		
		vector<vector<ll> > gr(m); // groups;
		fori(m){
			ll ki;
			cin>>ki;
			gr[i].resize(ki);
			forj(ki){
				cin>>gr[i][j];
			}
		}
		
		
		string ans = "";
		
		// add all the relavant counts
		fori(m){
			ll s = 0;
			ll ki = gr[i].size();
			forj(ki){
				s+=gr[i][j];
			}
			ll id = findte(s, (ll)gr[i].size(), arr);
			upd(1, 0, n, 0, id, -1);
		//	cout<<"adding -1 to "<<0<<" "<<id<<endl;
		}
		
		fori(m){
			ll s = 0;
			ll ki = gr[i].size();
			forj(ki){
				s+=gr[i][j];
			}
			ll id = findte(s, (ll)gr[i].size(), arr);
			upd(1, 0, n, 0 , id, 1);
			
			// check each one
			forj(ki){
				s -= gr[i][j];
				ll cid = findte(s, (ll)gr[i].size() - 1, arr);
				upd(1, 0, n, 0, cid, -1);
				
				ll cmin = mn[1];
				if(cmin < 0){
					ans += '0';
				}
				else{
					ans += '1';
				}
				 
				upd(1, 0, n, 0, cid, 1);  // undo
				s+=gr[i][j];
			}
			
			
			upd(1, 0, n, 0, id, -1); // undo
		}
		
		cout<<ans<<'\n';
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}