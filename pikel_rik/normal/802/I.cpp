#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

vector<int> suffixArray(string s) {
    s += char(0);
    int n = s.length();
    vector<int> sa(n);
    vector<int> c(n), cnt(max(256, n));
    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }
    for (int i = 1; i < 256; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
        sa[--cnt[s[i]]] = i;
    }
    c[sa[0]] = 0;
    int classes = 1;

    for (int i = 1; i < n; i++) {
        if (s[sa[i]] != s[sa[i - 1]])
            classes++;
        c[sa[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; h++) {
        for (int i = 0; i < n; i++) {
            pn[i] = (sa[i] + n - (1 << h)) % n;
        }

        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++) {
            cnt[c[pn[i]]]++;
        }
        for (int i = 1; i < classes; i++) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            sa[--cnt[c[pn[i]]]] = pn[i];
        }
        cn[sa[0]] = 0;
        classes = 1;

        for (int i = 1; i < n; i++) {
            if (c[sa[i]] != c[sa[i - 1]] or c[(sa[i] + (1 << h)) % n] != c[(sa[i - 1] + (1 << h)) % n]) {
                classes++;
            }
            cn[sa[i]] = classes - 1;
        }
        c.swap(cn);
    }
    sa.erase(sa.begin());
    return sa;
}

vector<int> LCP(const string& s, const vector<int>& sa) {
    int n = s.length();
    vector<int> lcp(n - 1), rank(n);
    for (int i = 0; i < n; i++) {
        rank[sa[i]] = i;
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = sa[rank[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
            k++;
        }
        lcp[rank[i]] = k;
        if (k) {
            k--;
        }
    }
    return lcp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		int n = s.length();
		vector<int> sa = suffixArray(s);
		vector<int> lcp = LCP(s, sa);

		vector<int> l(n - 1, -1), r(n - 1, n - 1), st;

		for (int i = 0; i < n - 1; i++) {
			while (!st.empty() and lcp[st.back()] >= lcp[i]) {
				st.pop_back();
			}
			if (!st.empty()) {
				l[i] = st.back();
			}
			st.push_back(i);
		}

		st.clear();
		for (int i = n - 2; i >= 0; i--) {
			while (!st.empty() and lcp[st.back()] >= lcp[i]) {
				st.pop_back();
			}
			if (!st.empty()) {
				r[i] = st.back();
			}
			st.push_back(i);
		}

		ll ans = ((ll)n * n + n) / 2 - accumulate(lcp.begin(), lcp.end(), 0ll);
		set<pair<int, int>> rep;
		for (int i = 0; i < n - 1; i++) {
			if (!rep.count(make_pair(l[i], r[i]))) {
				int range = r[i] - l[i], mn = max(l[i] != -1 ? lcp[l[i]] : 0, r[i] != n - 1 ? lcp[r[i]] : 0);
				ans += (ll) range * range * (lcp[i] - mn) - (lcp[i] - mn);
				rep.emplace(l[i], r[i]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}