#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
	fastIO;
	ll l, r;
	cin >> l >> r;
	cout << "YES\n";
	for(ll x = l; x < r; x += 2){
		cout << x << " " << x + 1 << "\n";
	}
	return 0;
}