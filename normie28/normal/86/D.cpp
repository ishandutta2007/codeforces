#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> qw;
const int MAXV = 1000010, MAXN = 200010, SQ = 450;
int num[MAXV], n, m, a[MAXN], cl, cr;
long long ans, res[MAXN];
vector<qw> qq[SQ];
bool cmp(qw a, qw b) {
	return a.first.second < b.first.second;
}
void movee(int k, int &v, bool op) {
	if (k < 0)
		while (k) {
			v--;
			if (op)
				ans += -2LL * (long long)num[a[v]] * a[v] + a[v], num[a[v]]--;
			else
				ans += 2LL * (long long)num[a[v]] * a[v] + a[v], num[a[v]]++;
			k++;
		}
	if (k > 0)
		while (k) {
			if (!op)
				ans += -2LL * (long long)num[a[v]] * a[v] + a[v], num[a[v]]--;
			else
				ans += 2LL * (long long)num[a[v]] * a[v] + a[v], num[a[v]]++;
			v++;
			k--;
		}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++) {
		cin >> cl >> cr;
		cl--;
		qq[cl / SQ].push_back({ { cl, cr }, i });
	}
	for (int i = 0; i < SQ; i++)
		sort(qq[i].begin(), qq[i].end(), cmp);
	cl = 0, cr = 1;
	num[a[0]]++;
	ans = a[0];
	for (int i = 0; i < SQ; i++)
		for (int j = 0; j < qq[i].size(); j++) {
			if (qq[i][j].first.second != cr)
				movee(qq[i][j].first.second - cr, cr, 1);
			if (qq[i][j].first.first != cl)
				movee(qq[i][j].first.first - cl, cl, 0);
			res[qq[i][j].second] = ans;
		}
	for (int i = 0; i < m; i++)
		cout << res[i] << '\n';
}