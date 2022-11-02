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
	foru(i, 0, n) {
		cin >> a[i];
	}
	int mx1 = 0, mx0 = 0;
	foru(i, 0, n) {
		if (a[i])mx1 = i;
		else mx0 = i;
	}
	cout << min(mx1, mx0) + 1;
	return 0;
}