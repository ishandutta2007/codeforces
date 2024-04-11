#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define F "BitLGM"
#define S "BitAryo"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main() {
	fast;
	ll n;
	cin >> n;
	if (n % 3 != 2) {
		cout << 1 << " " << 1 << " " << n - 2 << endl;
	}
	else {
		cout << 2 << " " << 2 << " " << n - 4 << endl;
	}
	return 0;
}