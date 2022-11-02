#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (auto &i : a) cin >> i;
	set<ll> sett;
	for (auto i : a) if (i > 0) sett.insert(i);
	cout << sett.size();
    return 0;
}