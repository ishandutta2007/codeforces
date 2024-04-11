// ./g-song-of-the-sirens.yml
#include <bits/stdc++.h>
using namespace std;

// Defines
#define fs first
#define sn second
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
// BaSc type definitions
#if __cplusplus == 201703L // CPP17 only things
template <typename T> using opt_ref = optional<reference_wrapper<T>>; // for some templates
#endif
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<long long, long long>;
#ifdef __GNUG__
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
#endif
// More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.reSze(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

/*
 * Assume `s` is a string that is 0-indexed
 * Let pi[i] -> longest proper prefix `k` of s[0..i] s.t. s[0..k-1] == s[i-k+1..i].  This is known as prefix property
 *
 * 1: pi[i-1] -> pi[i] can increase by at most 1.  If this was not the case, then we can delete the last character of
 * pi[i] and obtain a better result for pi[i-1]
 *
 * 2: To calculate pi[i] we enumerate all values `j` s.t. the prefix property holds for s[0..i-1], and pick the longest one
 * s.t. s[j] == s[i].  This follows from (1)
 *
 * 2a: We can do this by repeatedly picking the largest value of `j` we have not tried yet
 * 2b: To do this we can begin with pi[i-1] (which is by definition the largest `j`) and move iteratively from there
 * 2c: pi[i-1] allows us to map s[i-pi[i-1]+1..i] to s[0..pi[i-1]-1], which means that the next largest `j` will be at
 * pi[pi[i-1]-1] (which is the first pi[i-1] chars of s and is guaranteed to be less than pi[i-1].  We then repeat
 * iteratively until we find a value.
 */
template <typename Container> vector<int> kmp(int N, const Container &s) {
    vector<int> pi(N);
    for (int i = 1; i < N; i++) {
        int cur = pi[i-1];
        while (cur && s[i] != s[cur]) cur = pi[cur-1];
        if (s[i] == s[cur]) cur++;
        pi[i] = cur;
    }
    return pi;
}

const ll MOD = 1e9 + 7;
const int MN = 1e5 + 1, TH = 2e6-1;
int N, Q;
string t;
ll p2[MN], cnt[MN][26];
string S[MN];

string aroundMid(int idx, int len) {
    int mid = SZ(S[idx])/2;
    if (mid < len) return S[idx];
    return S[idx].substr(mid-len+1, 2*len-1);
}

void setMid(string &s, char c) {
    s[SZ(s)/2] = c;
}

ll occ(const string &s, const string &t) {
    string tmp = t + '$' + s;
    auto pi = kmp(SZ(tmp), tmp);
    return count(all(pi), SZ(t));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q >> S[0] >> t;

    int mx = -1;
    bool stop = false;
    for (auto i = 1; i <= N; i++) {
        for (auto j = 0; j < 26; j++)
            cnt[i][j] = cnt[i-1][j] * 2 % MOD;
        cnt[i][t[i-1]-'a']++;
        cnt[i][t[i-1]-'a'] %= MOD;

        if (!stop && SZ(S[i-1]) < TH) {
            S[i] = S[i-1] + t[i-1] + S[i-1];
            mx = i;
        }
        else stop = true;
    }
    
    // pow
    p2[0] = 1;
    for (auto i = 1; i < MN; i++)
        p2[i] = p2[i-1]*2 % MOD;

    while (Q--) {
        int k; string s; cin >> k >> s;

        ll ans = 0;

        // Copies of s0
        // cout<<"[qu]: "; cout<<"k="<<(k)<<", "; cout<<"s="<<(s)<<", "; cout << endl; // db l:qu,k,s
        // cout<<"s="<<(s)<<", "; cout<<"S[0]="<<(S[0])<<", "; cout<<"occ(S[0],s)="<<(occ(S[0],s))<<", "; cout << endl; // db s,S[0],occ(S[0],s)
        ans += occ(S[0], s) * p2[k] % MOD;
        
        vector<ll> sub(26);
        int lst = -1;
        for (auto i = 1; i <= min(k, mx); i++) {
            sub[t[i-1] - 'a'] = (sub[t[i-1] - 'a'] + p2[k-i]) % MOD;
            if (SZ(S[i]) < SZ(s)) continue;

            ans += occ(SZ(S[i]) > 2*SZ(s)-1 ? aroundMid(i, SZ(s)) : S[i], s) * p2[k-i] % MOD;
            if (i < k) lst = i+1;
            break;
        }
        
        if (lst != -1) {
            for (auto i = 0; i < 26; i++) {
                string cur = aroundMid(lst, SZ(s));
                setMid(cur, char('a'+i));

                ans += occ(cur, s) * (cnt[k][i] - sub[i]) % MOD;
            }
        }

        ans %= MOD;
        ans += MOD;
        ans %= MOD;

        cout << (ans) << '\n';
    }

    return 0;
}