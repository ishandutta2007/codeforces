#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, A, B, K, F, C, idx, tc, Y[605];
string L, R;
map<pair<string, string>, int> t;

pair<string, string> u(string L, string R) {
	return make_pair(min(L, R), max(L, R));
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> N >> A >> B >> K >> F;
	for (string P = ""; N--; P = R) {
		cin >> L >> R;
		if (L == P) C = B;
		else C = A;
		if (t[u(L, R)]) Y[t[u(L, R)]] += C;
		else t[u(L, R)] = ++idx, Y[idx] += C;
	}
	sort(Y + 1, Y + 1 + idx, greater<int>());
	for (int i = 1; i <= idx; i++) tc += Y[i];
	for (int i = 1; i <= min(K, idx); i++) {
		if (F < Y[i]) tc = tc - Y[i] + F;
		else break;
	} 
	cout << tc << '\n';
}