#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int a, b;

void Input() {
	cin >> a >> b;
}

void Solve() {
	if (a == b) {cout << "0\n"; return;}
	
	vector<int> Divisors;
	for (int i=1; i<=sqrt(max(a,b) - min(a,b)); i++) {
		if ((max(a,b) - min(a,b)) % i != 0) continue;
		int j = (max(a,b) - min(a,b)) / i;
		Divisors.push_back(i);
		if (i != j) Divisors.push_back(j);
	}
	
	pair<long long, int> Token = make_pair(LLONG_MAX, INT_MAX);
	for (auto d: Divisors) {
		int k = (d - a % d) % d;
		pair<long long, int> NewToken = make_pair(1LL * (0LL + a + k) / __gcd(0LL+a+k, 0LL+b+k) * (0LL + b + k), k);
		Token = min(Token, NewToken);
	}
	
	cout << Token.second << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); Input(); Solve();
	return 0;
}