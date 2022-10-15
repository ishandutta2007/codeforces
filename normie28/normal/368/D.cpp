#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
const ll inf = 1e18;
const int N = 2 * 1e5 + 10;
 
ll res;
ll a[N], b[N];
std::map<ll, ll> mp, mpp;
std::vector<ll> v, vv;
 
bool check(){
	if(mp.size() != mpp.size()) return false;
	for(auto i : mp){
		if(!mpp.count(i.first)){return false;}
		if(i.second != mpp[i.first]){return false;}
	}
	return true;
}
 
void seiv(ll n, ll p){
	for (int i = 1; i <= n; ++i){
		if(!a[i]){
			for (int j = i + p; j <= n; j += p){
				a[j] = 1;
			}
			v.push_back(i);
		}
	}
}
 
void go(ll idx, ll m, ll p, ll n){
	ll low = idx, high = low + (m - 1) * p;
	for (int i = low; i <= high; i += p){
		mpp[b[i]]++;
	}
	if(check()){vv.push_back(low);}
	while(high + p <= n){
		mpp[b[low]]--;
		if(!mpp[b[low]]) mpp.erase(b[low]);
		mpp[b[high + p]]++;
		low += p;
		high += p;
		if(check()){vv.push_back(low);}
	}
	mpp.clear();
}
 
void solve(){
	ll n, m, p;
	cin >> n >> m >> p;
	for (int i = 1; i <= n; ++i){
		cin >> b[i];
	}
	for (int i = 1; i <= m; ++i){
		ll x;
		cin >> x;
		mp[x]++;
	}
	seiv(n, p);
	for (int i = 0; i < v.size(); ++i){
		if(v[i] + (m - 1) * p > n) break;
		go(v[i], m, p, n);
	}
	cout << vv.size() << "\n";
	sort(vv.begin(), vv.end());
	for(auto i : vv){
		cout << i << " ";
	}
 
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
    ll t = 1;
    while(t--){
    	solve();
    }
}