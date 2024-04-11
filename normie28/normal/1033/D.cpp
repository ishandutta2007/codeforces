#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 #define break br
int M = 998244353;
 
ll gcd(ll a, ll b){
	return a==0 ? b : gcd(b%a, a);
}
 
int main(){
	int n; cin >> n;
	vector<ll> v(n);
	for(auto& x : v){
		ll y;
		cin >> y;
		x = y;
	}
 
	map<int,int> unfactored; 
	map<int,int> factors;
 
	for(int i = 0; i < n; ++i){
		ll a = v[i];
		for(int e = 4; e >= 2; --e){
			double root = pow(double(a), 1/double(e));
			for(int j = max(ll(1), ll(floor(root))-1); j <= ll(root)+1; ++j){
				ll z = 1;
				for(int k = 0; k < e; ++k)
					z *= j;
				if(z == a){
					factors[j] += e;
					goto break;
				}
			}
		}
		for(int j=0;j<n;++j){
			if(j==i) continue;
			if(v[j] == a) continue;
 
			ll g = gcd(a, v[j]);
			if(g > 1 && g < a){
				++factors[g];
				++factors[a/g];
				goto break;
			}
		}
		++unfactored[a];
break:;
	}
 
	long long ans = 1;
	for(auto x : factors){
		ans = ans * (x.second+1)%M;
	}
	for(auto x : unfactored){
		ans = ans * (x.second+1)%M * (x.second+1)%M;
	}
	cout << ans << endl;
}