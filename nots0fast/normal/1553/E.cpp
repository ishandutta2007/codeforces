#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision
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
#define mt make_tuple
#define MAX (int)(pow(10,6) + 5)
// #define cout out
// #define cin in
ll inf = pow(10, 18) + 100;
ll INF = pow(10, 9);
ll modulo = 998244353;
double eps = 1e-10;

bool check(vector<ll>& act, vector<ll>& arr, ll n, ll m){
/*	cout<<"actual "<<endl;
	fori(n){
		cout<<act[i]<<' ';
	}
	cout<<endl;
	cout<<"array "<<endl;
	fori(n){
		cout<<arr[i]<<' ';
	}
	cout<<endl;	*/
	vector<ll> spot(n, -1);
	fori(n){
		spot[act[i]] = i;
	}
	vector<bool> seen(n, 0);
	ll tot = 0;
	fori(n){
		if(spot[arr[i]] == i){
			continue;
		}
		if(seen[i]){
			continue;
		}
		ll cur = i;
//		cout<<"we gon go for "<<cur<<endl;
		if(!seen[cur]){
			--tot;
		}
		while(!seen[cur]){
			++tot;
			seen[cur] = 1;
			cur = spot[arr[cur]];
//			cout<<"cur now "<<cur<<endl;
		}
	}
//	cout<<tot<<" "<<m<<endl;
	return (tot <= m);
}

vector<ll> create(ll shif, ll n){
	vector<ll> arr(n);
	fori(n){
		arr[i] = (i-shif + n) % n;
	}
	return arr;
}

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n, m ;
		cin>>n>>m;
		map<ll, ll> s;
		vector<ll> arr(n);
		fori(n){
			ll ed;
			cin>>ed;
			--ed;
			arr[i] = ed;
			ll pos = (i - ed + n) % n;
			s[pos]++;
		}
		vector<ll> ans;
		for(auto& el : s){
			if(el.ss >= n-2*m){
				ans.pb(el.ff);
			}
		}
		vector<ll> tbh;
		for(auto& el : ans){
			vector<ll> cur = create(el, n);
			if(check(cur, arr, n, m)){
				tbh.pb(el);
			}
		}
		cout<<tbh.size()<<' ';
		for(auto& el: tbh){
			cout<<el<<' ';
		}
		cout<<'\n';
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	deal();
}