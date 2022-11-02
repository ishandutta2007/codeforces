#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

int main() {
	int n, s;
	cin >> n >> s;
	--s;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	assert(s);
	if(!a[0]) { cout << "NO\n"; return 0; }
	if(a[s]) { cout << "YES\n"; return 0; }
	if(b[s]) {
		for (int i = s; i < n; ++i) if(a[i] && b[i]) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}