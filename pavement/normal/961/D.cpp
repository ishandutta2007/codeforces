#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair

int N, X[100005], Y[100005];
bool I;
vector<pair<int, int> > V;

bool sameline(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	return (a.second - b.second) * (a.first - c.first) == (a.second - c.second) * (a.first - b.first);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	if (N == 1) return cout << "YES\n", 0;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
	// check line from (1, 2)
	if (X[1] == X[2]) {
		for (int i = 1; i <= N; i++)
			if (X[i] != X[1]) V.emplace_back(X[i], Y[i]);
	} else {
		for (int i = 1; i <= N; i++)
			if (!sameline(mp(X[1], Y[1]), mp(X[2], Y[2]), mp(X[i], Y[i]))) V.emplace_back(X[i], Y[i]);
	}
	if (V.size() <= 2) return cout << "YES\n", 0;
	I = 0;
	if (V[0].first == V[1].first) {
		for (auto i : V)
			if (V[0].first != i.first) I = 1; 
	} else {
		for (auto i : V)
			if (!sameline(V[0], V[1], i)) I = 1;
	}
	if (!I) return cout << "YES\n", 0;
	V.clear();
	// check line from (1, 3)
	if (X[1] == X[3]) {
		for (int i = 1; i <= N; i++)
			if (X[i] != X[1]) V.emplace_back(X[i], Y[i]);
	} else {
		for (int i = 1; i <= N; i++)
			if (!sameline(mp(X[1], Y[1]), mp(X[3], Y[3]), mp(X[i], Y[i]))) V.emplace_back(X[i], Y[i]);
	}
	if (V.size() <= 2) return cout << "YES\n", 0;
	I = 0;
	if (V[0].first == V[1].first) {
		for (auto i : V)
			if (V[0].first != i.first) I = 1; 
	} else {
		for (auto i : V)
			if (!sameline(V[0], V[1], i)) I = 1;
	}
	if (!I) return cout << "YES\n", 0;
	V.clear();
	// check line from (2, 3)
	if (X[2] == X[3]) {
		for (int i = 1; i <= N; i++)
			if (X[i] != X[2]) V.emplace_back(X[i], Y[i]);
	} else {
		for (int i = 1; i <= N; i++)
			if (!sameline(mp(X[2], Y[2]), mp(X[3], Y[3]), mp(X[i], Y[i]))) V.emplace_back(X[i], Y[i]);
	}
	if (V.size() <= 2) return cout << "YES\n", 0;
	I = 0;
	if (V[0].first == V[1].first) {
		for (auto i : V)
			if (V[0].first != i.first) I = 1; 
	} else {
		for (auto i : V)
			if (!sameline(V[0], V[1], i)) I = 1;
	}
	if (!I) return cout << "YES\n", 0;
	cout << "NO\n";
}