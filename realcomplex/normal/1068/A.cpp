#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())

int main(){
	fastIO;
	ll n, m, k , l;
	cin >> n >> m >> k >> l;
	ll tot = k + l;
	if(tot > n){
		cout << -1;
		exit(0);
	}
	ll each = (tot + m - 1) / m;
	if(each * m > n){
		cout << -1;
		exit(0);
	}
	cout << each;
	return 0;
}