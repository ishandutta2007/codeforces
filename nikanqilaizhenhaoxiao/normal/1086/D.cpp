#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, q;
	string s;
	cin >> n >> q >> s;
	set<int> sr, sp, ss;
	vector<int> fr(n + 1, 0), fp(n + 1, 0), fs(n + 1, 0);
	auto lowbit = [&](int i) { return i & (-i); };
	auto M = [&](vector<int> &a, int i, int x) { for (; i <= n; i += lowbit(i)) a[i] += x; return; };
	auto Q = [&](vector<int> &a, int i) { int x = 0; for(; i; i ^= lowbit(i)) x += a[i]; return x; };
	auto Qlr = [&](vector<int> &a, int l, int r) { if(l > r) return 0; return Q(a, r) - Q(a, l - 1); };
	for (int i = 0; i < n; ++i) {
		if(s[i] == 'R') sr.insert(i), M(fr, i + 1, 1);
		if(s[i] == 'P') sp.insert(i), M(fp, i + 1, 1);
		if(s[i] == 'S') ss.insert(i), M(fs, i + 1, 1);
	}
	auto solve = [&]() {
		int ret = 0;
		auto work = [&](set<int> &sr, set<int> &sp, set<int> &ss, vector<int> &fr, vector<int> &fp, vector<int> &fs) {
			if(!sr.size()) return;
			if(sp.empty()) ret += sr.size();
			else if(!ss.empty()) {
				vector<pair<int, int> > ban_range;
				int firstp = *sp.begin(), firsts = *ss.begin();
				if(firstp < firsts) ban_range.push_back(make_pair(firstp, firsts));
				int lastp = *sp.rbegin(), lasts = *ss.rbegin();
				if(lastp > lasts) ban_range.push_back(make_pair(lasts, lastp));
#ifdef DEBUGg
				cerr << s << endl;
				cerr << firstp << ' ' << lastp << '\t' << firsts << ' ' << lasts << endl;
				cerr << ban_range.size() << endl;
				for (auto t: ban_range) cerr << t.first << ' ' << t.second << endl;
#endif
				ret += sr.size();
				if(ban_range.size() == 1) ret -= Qlr(fr, ban_range[0].first + 1, ban_range[0].second + 1);
				else if(ban_range.size() == 2) {
					if(ban_range[0].first > ban_range[1].first) swap(ban_range[0], ban_range[1]);
					if(ban_range[0].second >= ban_range[1].first) ret -= Qlr(fr, ban_range[0].first + 1, max(ban_range[0].second, ban_range[1].second) + 1);
					else ret -= Qlr(fr, ban_range[0].first + 1, ban_range[0].second + 1), ret -= Qlr(fr, ban_range[1].first + 1, ban_range[1].second + 1);
				}
			}
		};
		work(sr, sp, ss, fr, fp, fs);
#ifdef DEBUGg
		cout << ret << endl;
#endif
		work(sp, ss, sr, fp, fs, fr);
#ifdef DEBUGg
		cout << ret << endl;
#endif
		work(ss, sr, sp, fs, fr, fp);
		cout << ret << endl;
		return;
	};
	solve();
	while(q--) {
		int i; char c;
		cin >> i >> c;
		--i;
		if(s[i] == 'R') sr.erase(i), M(fr, i + 1, -1);
		if(s[i] == 'P') sp.erase(i), M(fp, i + 1, -1);
		if(s[i] == 'S') ss.erase(i), M(fs, i + 1, -1);
		s[i] = c;
		if(s[i] == 'R') sr.insert(i), M(fr, i + 1, 1);
		if(s[i] == 'P') sp.insert(i), M(fp, i + 1, 1);
		if(s[i] == 'S') ss.insert(i), M(fs, i + 1, 1);
		solve();
	}
	return 0;
}