#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

int main(){
	fastIO;
	int n;
	cin >> n;
	if(n <= 2){
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	ll s = (1ll * n * (n + 1))/2;
	for(ll i = 1;i <= n;i ++ ){
		if(__gcd((s - i), i) > 1){
			cout << 1 << " " << i << "\n";
			cout << n - 1 << " ";
			for(ll j = 1; j <= n;j ++ ){
				if(i != j)
					cout << j << " ";
			}
			cout << "\n";
			return 0;
		}
	}
	return 0;
}