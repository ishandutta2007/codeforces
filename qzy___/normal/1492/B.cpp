#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int T;
int n, p[100010];
multiset <int> s;

int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--) {
		s.clear();
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> p[i];
		for(int i = 1; i <= n; i++) s.insert(i);
		int now = n;
		while(s.size()) {
			int t = *(--s.end()), ed = 0;
			for(int i = now; i; i--)
				if(p[i] == t) {
					ed = i;
					break;
				}
			for(int i = ed; i <= now; i++)
				s.erase(s.find(p[i])), cout << p[i] << " ";
			now = ed - 1;
		}
		cout << "\n";
	}
	return 0;
}