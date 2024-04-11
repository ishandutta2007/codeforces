#include <bits/stdc++.h>

using namespace std;

const int D = 510;
const int S = 5010;

int used[D][S];
int traceNumber[D][S];
pair<int, int> trace[D][S];

int main() {
	int d, s;
	cin >> d >> s;
	queue<pair<int, int> > q;
	q.push({0, 0});
	used[0][0] = 1;
	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		for (int i = 0; i < 10; i++) {
			int foo = (u.first * 10 + i) % d;
			int bar = u.second + i;
			if (bar > s) continue;
			if (used[foo][bar]) continue;
			used[foo][bar] = 1;
			q.push({foo, bar});
			traceNumber[foo][bar] = i;
			trace[foo][bar] = u;
		}
	}
	if (!used[0][s]) {
		cout << -1 << endl;
	} else {
		pair<int, int> u(0, s);
		string res = "";
		while (u != pair<int, int>(0, 0)) {
			res += (char)(traceNumber[u.first][u.second] + '0');
			u = trace[u.first][u.second];
		}
		reverse(res.begin(), res.end());
		cout << res << endl;
	}
	return 0;
}