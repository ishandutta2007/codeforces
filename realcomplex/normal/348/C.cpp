#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())

const ll N = (ll)1e5 + 9;
const ll B = 350;

int c[N][B];
ll ind[N];
vector<ll> T[N];
vector<ll> id;
ll arr[N];
ll z[N];
ll tot[N];
bool ok[N];

int main(){
	fastIO;
	ll n, m, q;
	cin >> n >> m >> q;
	for(ll i = 1; i <= n; i ++ ){
		cin >> arr[i];
	}
	ll s, x;
	for(ll j = 1; j <= m; j ++ ){
		cin >> s;
		for(ll i = 0 ; i < s; i ++ ){
			cin >> x;
			T[j].push_back(x);
		}
		if(s < B){
			ind[j] = -1;
		}
		else{
			ind[j] = (ll)id.size();
			id.push_back(j);
		}
	}
	for(ll i = 1; i <= m; i ++ ){
		if(ind[i] == -1)
			continue;
		for(ll j = 1; j <= n; j ++ ){
			ok[j] = false;
		}
		for(auto P : T[i]){
			ok[P] = true;
			z[i] += arr[P];
		}
		for(ll j = 1; j <= m; j ++ ){
			for(auto P : T[j]){
				c[j][ind[i]] += ok[P];
			}
		}
	}
	char op;
	ll pi;
	ll add;
	ll ans;
	for(ll i = 0 ; i < q; i ++ ){
		cin >> op;
		if(op == '?'){
			cin >> pi;
			if(ind[pi] !=  -1){
				cout << z[pi] << "\n";
			}
			else{
				ans = 0ll;
				for(auto P : T[pi]){
					ans += arr[P];
				}
				for(ll j = 0; j < id.size(); j ++ ){
					ans +=1ll * c[pi][j] * tot[id[j]];
				}
				cout << ans << "\n";
			}
		}
		else{
			cin >> pi >> add;
			tot[pi] += add;
			if(ind[pi] == -1){
				for(auto P : T[pi])
					arr[P] += add;
			}
			for(ll j = 0 ; j < id.size(); j ++ ){
				z[id[j]] += 1ll * c[pi][j] * add;
			}
		}
	}
	return 0;
}