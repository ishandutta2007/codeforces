#include <bits/stdc++.h>
using namespace std;

int N;
pair<string, int> tmp[205];
string s[205];
char ans[205];
bool inv;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < 2 * N - 2; i++) cin >> tmp[i].first, tmp[i].second = i;
	sort(tmp, tmp + 2 * N - 2, [](const pair<string, int> &a, const pair<string, int> &b) {
		return b.first.size() > a.first.size();
	});
	for (int i = 0; i < 2 * N - 2; i++)
		s[i] = tmp[i].first;
	string at = "", bt = "";
	for (int i = 0; i < 2 * N - 2; i += 2) {
		at.push_back(s[2 * N - 3][i / 2]);
		bt.insert(0, s[2 * N - 4].substr(N - 1 - i / 2 - 1, 1));
		if ((at == s[i] && bt == s[i + 1]) || (at == s[i + 1] && bt == s[i])) {
			int cur = tmp[i].second;
			if (at == s[i] && bt == s[i + 1]) ans[cur] = 'P', ans[tmp[i + 1].second] = 'S';
			else ans[cur] = 'S', ans[tmp[i + 1].second] = 'P';
		} else {
			inv = 1;
			break;
		}
	}
	if (!inv) {
		for (int i = 0; i < 2 * N - 2; i++)
			cout << ans[i];
		cout << '\n';
		return 0;
	}
	inv = 0;
	at = bt = "";
	for (int i = 0; i < 2 * N - 2; i += 2) {
		at.insert(0, s[2 * N - 3].substr(N - 1 - i / 2 - 1, 1));
		bt.push_back(s[2 * N - 4][i / 2]);
		int cur = tmp[i].second;
		if (at == s[i] && bt == s[i + 1]) ans[cur] = 'S', ans[tmp[i + 1].second] = 'P';
		else ans[cur] = 'P', ans[tmp[i + 1].second] = 'S';
	}
	for (int i = 0; i < 2 * N - 2; i++)
		cout << ans[i];
	cout << '\n';
}