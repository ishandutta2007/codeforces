#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define L first
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define R second
#define smin(x, y) (x) = min((x), (y))
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()

#define base sdsdasd
#define hash fksdlfk

const int maxn = 2000 * 1001;
const LL Mod = 1000 * 1000 * 1000 + 7;
const int hashcnt = 2;
const LL HMod[hashcnt] = {1000 * 1000 * 1000 + 7, 1000 * 1000 * 1000 + 9};
const LL base[hashcnt] = {313, 353};
int pw[maxn][hashcnt];
int sum[maxn / 2][26];
string t;
bool pre[maxn],
     suf[maxn];
int ssiz;

struct hashstr {
    string str;
    vector<LL> hash[hashcnt];
    
    void build () {
        for (int i = 0; i < hashcnt; i++) {
            hash[i].reserve(sz(str) + 1);
            hash[i].PB(0);
            for (int j = 0; j < sz(str); j++)
                hash[i].PB((hash[i].back() * base[i] + str[j]) % HMod[i]);
        }
    }

    LL get(int st, int en, int i) {
        return ((hash[i][en] - hash[i][st] * pw[en - st][i]) % HMod[i] + HMod[i]) % HMod[i];
    }

    pair<int, int> get(int st, int en) {
        return MP(get(st, en, 0), get(st, en, 1));
    }
};
hashstr s[50];

LL Pow(LL x, LL y) {
    LL ans = 1,
       an = x % Mod;
    while (y) {
        if (y & 1LL)
            ans = ans * an % Mod;
        an = an * an % Mod;
        y >>= 1;
    }
    return ans;
}

LL Inv(LL x) { return Pow(x, Mod - 2); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int j = 0; j < hashcnt; j++)
        pw[0][j] = 1;
    for (int i = 1; i < maxn; i++)
        for (int j =0 ; j < hashcnt; j++)
            pw[i][j] = pw[i - 1][j] * base[j] % HMod[j];

    int n, q;
    cin >> n >> q;

    cin >> s[0].str;
    s[0].build();

    cin >> t;
    for (int i = 0; i < sz(t); i++) {
        for (int j = 0; j < 26; j++)
            sum[i + 1][j] = sum[i][j] * 2 % Mod;
        sum[i + 1][t[i] - 'a'] += 1;
        sum[i + 1][t[i] - 'a'] %= Mod;
    }

    ssiz = 1;
    for (int i = 0; sz(s[i].str) <= 1000 * 1000; i++) {
        s[i + 1].str = s[i].str + t[i] + s[i].str;
        s[i + 1].build();
        ssiz++;
    }

    while (q--) {
        int pos;
        hashstr w;
        cin >> pos >> w.str;
        w.build();
        for (auto &c: w.str)
            c -= 'a';

        int idx = 0;
        while (sz(s[idx].str) < sz(w.str))
            idx++;
        if (idx > pos) {
            cout << 0 << '\n';
            continue;
        }
        
        for (int i = 0; i < sz(w.str); i++) {
            if (s[idx].get(0, i) == w.get(sz(w.str) - i, sz(w.str)))
                suf[i] = true;
            else
                suf[i] = false;
            
            if (s[idx].get(sz(s[idx].str) - i, sz(s[idx].str)) == w.get(0, i))
                pre[i] = true;
            else
                pre[i] = false;
        }
        
        LL cnt[26] = {0LL};
        for (int i = 0; i < sz(w.str); i++)
            cnt[w.str[i]] += pre[i] and suf[sz(w.str) - i - 1];
        LL kol = pos - idx;
        LL ans = 0;
        for (int i = 0; i < 26; i++) {
            LL cur = (sum[pos][i] - sum[idx][i] * Pow(2, pos - idx)) % Mod;
            ans = (ans + cur * cnt[i]) % Mod;
        }
        ans = (ans + Mod) % Mod;
        LL occ = 0;
        for (int i = 0; i + sz(w.str) <= sz(s[idx].str); i++)
            if (s[idx].get(i, i + sz(w.str)) == w.get(0, sz(w.str)))
                occ++;
        ans = (ans + Pow(2, pos - idx) * occ) % Mod;
        cout << ans << '\n';
    }
    return 0;
}