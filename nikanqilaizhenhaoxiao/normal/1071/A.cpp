#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	long long c = a + b;
	long long n = 0;
	while((n + 1) * (n + 2) / 2 <= c) ++n;
	vector<long long> p, q;
	for (long long i = n; i; --i) if(a >= i) a -= i, p.push_back(i); else q.push_back(i);
	cout << p.size() << endl;
	for (auto x: p) cout << x << ' ';
	cout << endl;
	cout << q.size() << endl;
	for (auto x: q) cout << x << ' ';
	cout << endl;
	return 0;
}