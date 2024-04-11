#include <bits/stdc++.h>
using namespace std;
int main() 
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	
	string s; cin >> s;
	priority_queue<pair<int, int>> pq;
	int p = 0;
	long long ans = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(') ++p;
		else if (s[i] == ')')--p;
		else {
			s[i] = ')';
			--p;
			int a, b; cin >> a >> b;
			ans += b;
			pq.push({b - a, i});
		}
		if (p < 0) {
			if (pq.empty()) break;
			p += 2;
			s[pq.top().second] = '(';
			ans -= pq.top().first;
			pq.pop();
		}
	}
	if (p != 0) cout << "-1";
	else cout << ans << "\n" << s;

	return 0;	
}