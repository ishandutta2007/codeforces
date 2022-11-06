#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
typedef long double ld;

string prv = "+", tmp;
int N, pos, neg, apos = -1, aneg = -1;
pair<int, bool> O[205];
vector<int> ppos, npos;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 1; cin >> tmp; ) {
		if (tmp == "?") {
			if (prv == "+") pos++, ppos.pb(i++);
			else neg++, npos.pb(i++);
		} else if (tmp == "+" || tmp == "-") prv = tmp;
		else if (tmp != "=") N = stoi(tmp);
	}
	for (int i = max(pos, N); i <= pos * N; i++) {
		if (neg <= i - N && i - N <= neg * N) {
			apos = i;
			aneg = i - N;
			break;
		}
	}
	if (apos == -1) return cout << "Impossible\n", 0;
	for (int i = 0; i < ppos.size(); i++) {
		O[ppos[i]] = mp(min(N, apos - ppos.size() + i + 1), 1);
		apos -= O[ppos[i]].first;
	}
	for (int i = 0; i < npos.size(); i++) {
		O[npos[i]] = mp(min(N, aneg - npos.size() + i + 1), 0);
		aneg -= O[npos[i]].first;
	}
	cout << "Possible\n" << O[1].first;
	for (int i = 2; i <= ppos.size() + npos.size(); i++)
		if (O[i].second) cout << " + " << O[i].first;
		else cout << " - " << O[i].first;
	cout << " = " << N << '\n';
}