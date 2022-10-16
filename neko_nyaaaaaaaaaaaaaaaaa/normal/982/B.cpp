#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	vector<pair<int, int>> w(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i].first;
		w[i].second = i+1;
	}
	string s;
	cin >> s;
	
	sort(w.begin(), w.end());
	int pt = 0;
	
	priority_queue<pair<int, int>> q;
	for (int i = 0; i < 2*n; i++) {
		if (s[i] == '0') {
			cout << w[pt].second << " ";
			q.push(w[pt]);
			pt++;
		} else {
			cout << q.top().second << " ";
			q.pop();
		}
	}
	
	return 0;
}