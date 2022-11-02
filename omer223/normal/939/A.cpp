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

const int sz = 5e5;
int a[sz];
int main() {
	fast;
	ll n;
	cin >> n;
	foru(i, 0, n)cin >> a[i + 1];
	foru(i, 0, n)if (a[a[a[i + 1]]] == i + 1) {
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO";
	return 0;
}