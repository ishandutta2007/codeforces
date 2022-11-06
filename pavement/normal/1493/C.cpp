#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N, K, ans, cnt[26];
char S[100005];
vector<ii> need;

int clos(int a, int b) {
	if (a == 0) return 0;
	return (b + a - 1) / b * b;
}

bool can(int k) {
	need.clear();
	for (int i = 0; i < 26; i++) {
		int x = clos(cnt[i], K) - cnt[i];
		k -= x;
		need.eb(i, x);
		//cout << i << ' ' << cnt[i] << ' ' << clos(cnt[i], K) << " NEED " << x << '\n';
	}
	if (k < 0 || k % K) return 0;
	need.eb(0, k);
	return 1;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> K;
		memset(cnt, 0, sizeof cnt);
		ans = 0;
		for (int i = 1; i <= N; i++) cin >> S[i], cnt[S[i] - 'a']++;
		bool inv = 0;
		for (int i = 0; i < 26; i++)
			if (cnt[i] % K) inv = 1;
		if (!inv) {
			for (int i = 1; i <= N; i++) cout << S[i];
			cout << '\n';
			continue;
		}
		memset(cnt, 0, sizeof cnt);
		for (int i = 1; i <= N; i++) {
			for (int j = S[i] + 1; j <= 'z'; j++) {
				cnt[j - 'a']++;
				if (can(N - i)) {
					cnt[j - 'a']--;
					ans = i;
					break;
				}
				cnt[j - 'a']--;
			}
			cnt[S[i] - 'a']++;
		}
		if (ans == 0) {
			cout << "-1\n";
			continue;
		}
		memset(cnt, 0, sizeof cnt);
		for (int i = 1; i < ans; i++)
			cnt[S[i] - 'a']++;
		bool yes = 0;
		for (int j = S[ans] + 1; j <= 'z'; j++) {
			cnt[j - 'a']++;
			//cout << "# " << j - 'a' << '\n';
			//for (int k = 0; k < 26; k++) cout << cnt[k] << ' ';
			//cout << '\n';
			if (can(N - ans)) {
				//cout << "@ " << j - 'a' << '\n';
				cnt[j - 'a']--;
				S[ans] = j;
				string tmp = "";
				for (auto i : need)
					for (int k = 0; k < i.second; k++)
						tmp.pb(i.first + 'a');
				sort(tmp.begin(), tmp.end());
				for (int i = 1; i <= ans; i++) cout << S[i];
				cout << tmp << '\n';
				yes = 1;
				break;
			}
			cnt[j - 'a']--;
		}
		assert(yes);
	}
}