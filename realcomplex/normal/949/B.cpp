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

int main(){
	fastIO;
	ll n;
	int q;
	cin >> n>> q;
	ll pos;
	while(q--){
		cin >> pos;
		while(pos%2 == 0){
			pos = n + pos / 2;
		}
		cout << pos/2+1 << "\n";
	}
	return 0;
}