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
	ll b;
	cin >> b;
	ll ans = 0;
	for(ll i = 1; i * i <= b; i ++ ){
		if(b % i == 0){
			ans ++ ;
			if(i * i != b)
				ans ++ ;
		}
	}
	cout << ans << "\n";
	return 0;
}