#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())

int rem = 100000;

void add(ll x){
	cout << x << " ";
	rem -- ;
	if(rem == 0)
		exit(0);
}

vector<ll> dv;
ll k;

void dfs(ll u, int dep){
	if(u == 1){
		add(1);
		return;
	}
	if(dep + 1 <= k){
		for(auto x : dv){
			if(x > u)
				break;
			if(u % x == 0){
				dfs(x, dep + 1);
			}
		}
	}
	if(dep == k){
		add(u);
	}
}

int main(){
	fastIO;
	ll x;
	cin >> x >> k;
	for(ll i = 1; i * i <= x; i ++){
		if(x % i == 0){
			dv.push_back(i);
			if(x / i != i){
				dv.push_back(x/i);
			}
		}
	}
	sort(dv.begin(), dv.end());
	dfs(x, 0);
	return 0;
}