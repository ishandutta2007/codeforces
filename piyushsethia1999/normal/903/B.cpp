#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int h1; cin >> h1;
	int a1; cin >> a1;
	int c1; cin >> c1;
	int h2; cin >> h2;
	int a2; cin >> a2;
	int attacks = ((h2 + a1 - 1) / (a1));
	int att = attacks - 1;
	int minh = a2 * att;
	att = 0;
	while (h1 <= minh) {
		att++; h1 += (c1 - a2);
	} 
	cout << att + attacks << "\n";
	for (int i = 0; i < att; ++i) {
		cout << "HEAL\n";
	}
	for (int i = 0; i < attacks; ++i) {
		cout << "STRIKE\n";
	}
}