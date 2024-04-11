#include <bits/stdc++.h>
using namespace std;

#define int long long

bool allis(string s, char c) {
	for (char cc: s) {
		if (c != cc) return 0;
	}
	return 1;
}

void solve1(int n, int a, int b, int c, string s) {
	int opa = 0, opb = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] == '0' && s[i-1] == '0') opa++;
		else if (s[i] == '1' && s[i-1] == '1') opb++;
	}

	if (opa == opb) {
		cout << opa*a + opb*b << '\n';
	} else if (opa > opb) {
		cout << (opb+1)*a + opb*b << '\n';
	} else {
		cout << opa*a + (opa+1)*b << '\n';
	}
}

int try_solve(int a, int b, int c, vector<int> p0, int p1, int fila, int side, int st) {
	if (st == 1 && p1 == 0) {
		//cout << "Answer 1 0\n";
		return 0;
	} 
	//cout << "Answer " << st;

	int ans = 0, sum = 0;

	// 1: step a, on p0
	// 2: step a, on fila
	// 3: step b
	// 4: step c, on p0
	// 5: step c, on side

	// first, keep going until fail
	// st first
	// end step must be step b
	if (st == 1) {
		sum += b; ans += b;
		p1--;
	}

	int petr = (int)p0.size() - 1;
	while (p1 > 0) {
		// a then b
		while (petr >= 0 && p0[petr] == 1) petr--;
		if (petr == -1) {
			if (fila == 0) break;

			fila--; p1--;
			sum += a+b; ans += a+b;
		} else {
			// try from petr
			p0[petr]--; p1--;
			sum += a+b; ans += a+b;
		}
	}
	//cout << st << ' ' << sum << '\n';

	// we have exhausted either (p0 and fila) or p1
	// we must start from step a

	// if p1 is exhausted
	// then we can erase 1 from p0 for a prize of b-c
	// erase all 1s
	// if after	that, either p0 or fila still has content
	// then we get a bonus

	// if p1 is not exhausted, then (p0 and fila exhausted)
	// then we can erase every 0 left (unless side = 2 then we leave one zero)

	if (p1 == 0) {
		// there might still be 0 operations, but who tf cares
		while (p0.size() && p0.back() == 1) {
			sum += b-c; p0.pop_back();
		}
		if (fila > 0 || p0.size()) {
			sum += a;
		}
		ans = max(ans, sum);
	} else {
		// p0 and fila exhausted, but there might be 0 left
		while (p0.size() && p0.back() == 1) {
			sum += b-c; p0.pop_back();
		}
		while (p1 > 0 && side > 0) {
			sum += b-c; side--; p1--;
		}
		ans = max(ans, sum);
	}

	//cout << ' ' << ans << '\n';
	return ans;
}

void solve2(int n, int a, int b, int c, string s) {
	// c then b actually profits
	// we have piles of 0
	// and piles of ones
	// start with either, can try brute
	// strategy: remove from the smallest 0-pile first
	// operations are of type ababababab
	// if a fails, then try c immediately
	// if b fails, then rollback one step
	// if last step is a, then try c-merge first
	// if there aren't c-merge, then try c-lone
	// if last step is c, this is end of the line
	// 1-pile can be removed arbitrarily, don't matter
	
	vector<int> p0; int p1 = 0, p0fila = 0, side = 0;
	for (int i = 0; i < n;) {
		int j = i;
		while (j < n && s[j] == s[i]) j++;
		if (s[i] == '0') {
			p0.push_back(j-i);
		} else {
			p1 += (j-i-1);
		}
		i = j;
	}

	if (s[0] == '0') {
		p0fila += p0[0]-1; side++;
		p0.erase(p0.begin());
	}
	if (s[n-1] == '0') {
		p0fila += p0.back()-1; side++;
		p0.pop_back();
	}

	// cout << "STATS\n";
	// cout << p1 << ' ' << p0fila << ' ' << side << '\n';
	// for (int i: p0) cout << i << ' ';
	// 	cout << '\n';

	sort(p0.begin(), p0.end(), greater<int>());
	cout << max(
		try_solve(a, b, c, p0, p1, p0fila, side, 0),
		try_solve(a, b, c, p0, p1, p0fila, side, 1)
	) << '\n';
}

void solve() {
	int n, a, b, c; cin >> n >> a >> b >> c;
	string s; cin >> s;
	if (n == 1) {
		cout << "0\n";
		return;
	}
	if (allis(s, '0')) {
		cout << a << '\n';
		return;
	}
	if (allis(s, '1')) {
		cout << b << '\n';
		return;
	}

	if (c >= b) {
		solve1(n, a, b, c, s);
	} else {
		solve2(n, a, b, c, s);
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}