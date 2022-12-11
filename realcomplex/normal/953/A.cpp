#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

int main(){
	fastIO;
	ll l,r;
	cin >> l >> r;
	vector<ll>div,tr;
	div.push_back(1);
	ll k = 1;
	while(k < (ll)2e9){
		k *= 3;
		div.push_back(k);
	}
	k=  1;
	tr.push_back(1);
	while(k < (ll)2e9){
		k *= 2;
		tr.push_back(k);
	}
	ll ans = 0;
	for(auto x : div){
		for(auto y : tr){
			if( x * y >= l and x * y <= r){
				ans ++ ;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}