// Not my code
// https://codeforces.com/contest/1466/submission/102943566
 
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef int int2;
//#define int long long
 
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define sz(x) (int)(x).size()
const int mod = 1e9 + 7;
 
int reduce(int a) {
    return a >= mod ? a - mod : a;
}
 
int add(int a, int b) {
    return reduce(a + b);
}
 
int prod(int a, int b) {
    return (long long) a * b % mod;
}
 
int modpow(int a, int pw) {
    if (pw == 0) return 1;
    if (pw % 2 == 0) {
        int res = modpow(a, pw / 2);
        return prod(res, res);
    }
    return prod(a, modpow(a, pw - 1));
}
 
int inv(int a) {
    return modpow(a, mod - 2);
} 
 
vector<int> pi(const string& s) {
	vector<int> p(sz(s));
	for(int i = 1; i < sz(s); ++i) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}
 
int match_count(const string& s, const string& pat) {
	vector<int> p = pi(pat + '\0' + s);
    int res = 0;
	for(int i = sz(p)-sz(s); i < sz(p); ++i)
		if (p[i] == sz(pat)) ++res;
	return res;
}
 
int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    string s0;
    cin >> s0;
    int len0 = s0.size();
    string ts;
    cin >> ts;
    vector<array<int,26>> pre_freqs(n + 1);
    for (int i = 1; i <= n; i++) {
        pre_freqs[i][ts[i - 1] - 'a']++;
        for (int j = 0; j < 26; j++) {
            pre_freqs[i][j] = reduce(pre_freqs[i][j] + reduce(2 * pre_freqs[i - 1][j]));
        }
    }
    
    vector<int> twopows(n + 1);
    twopows[0] = 1;
    for (int i = 1; i <= n; ++i)
        twopows[i] = reduce(2 * twopows[i - 1]);
 
    for (int qq = 1; qq <= q; qq++) {
        int k;
        cin >> k;
        string w;
        cin >> w;
        int wlen = w.size();
        string proxy = s0;
        int i = 0;
        while (i < k and (int)proxy.size() < wlen) {
            proxy = proxy + ts[i] + proxy;
            i++;
        }
        // i = number of times I add a character in the middle
        if (i == k) {
            int ans = match_count(proxy, w);
            cout << ans << "\n";
        } else {
            array<int, 26> intersection_cnt{};
            array<int, 26> freq{};
 
            int num_matches = match_count(proxy, w);
            for (char ch = 'a'; ch <= 'z'; ch++) {
                string next_proxy = proxy + ch + proxy;
                intersection_cnt[ch - 'a'] = match_count(next_proxy, w) - 2 * num_matches;
            }
            int ans = 0;
            for (int j = 0; j < 26; j++) {
                // count contribution of added characters from time (i + 1)...(k)
                int num_occurrences = reduce(pre_freqs[k][j] - prod(pre_freqs[i][j], twopows[k - i]) + mod);
                ans = reduce(ans + prod(intersection_cnt[j], num_occurrences));
            }
            int total_occ = prod(num_matches, twopows[k - i]);
            ans = reduce(ans + total_occ);
 
            cout << ans << "\n";
        }
    }
}