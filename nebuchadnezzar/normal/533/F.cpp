#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 2e5 + 5;
const LL P = 29, MOD = 1e9 + 9;

int ls, lt;
string s, t;
int next[26][MAXN];
int now[26];
LL parr[MAXN];
LL hash[MAXN];
LL thash[26];

int get_hash(int l, int r) {
    LL tmp = (hash[r + 1] - hash[l] * parr[r - l + 1]) % MOD;
    if (tmp < 0) {
        tmp += MOD;
    }
    return tmp;
}

int to[26];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    parr[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        parr[i] = (parr[i - 1] * P) % MOD;
    }

    cin >> ls >> lt;
    cin >> s >> t;

    for (int i = 0; i < ls; ++i) {
        hash[i + 1] = (hash[i] * P + s[i] - 'a' + 1) % MOD;
        //cerr << hash[i + 1] << endl;
    }

    //cerr << get_hash(1, 1);

    for (int i = 0; i < lt; ++i) {
        for (int j = 0; j < 26; ++j) {
            thash[j] = (thash[j] * P) % MOD;
        }
        thash[t[i] - 'a'] = (thash[t[i] - 'a'] + 1) % MOD;
    }

    for (int i = 0; i < 26; ++i) {
        now[i] = ls;
    }

    for (int i = ls - 1; i >= 0; --i) {
        now[s[i] - 'a'] = i;
        for (int j = 0; j < 26; ++j) {
            next[j][i] = now[j];
        }
    }

    vector <int> ans;

    for (int i = 0; i < ls - lt + 1; ++i) {
        for (int j = 0; j < 26; ++j) {
            to[j] = j;
        }
        for (int j = 0; j < 26; ++j) {
            //cerr << next[j][i] << endl;
            if (next[j][i] < i + lt) {
                to[j] = t[next[j][i] - i] - 'a';
                to[t[next[j][i] - i] - 'a'] = j;
            }
        }
        /*
        cerr << "i: " << i << endl;
        for (int j = 0; j < 26; ++j) {
            cerr << to[j] << endl;
        }
        */
        bool flag = true;
        for (int j = 0; j < 26; ++j) {
            if (j != to[to[j]]) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            continue;
        }
        //cerr << i << endl;
        LL nh = 0;
        for (int j = 0; j < 26; ++j) {
            nh = (nh + thash[j] * (to[j] + 1)) % MOD;
        }
        //cerr << nh << " " << get_hash(i, i + lt - 1) << endl;
        if (nh == get_hash(i, i + lt - 1)) {
            ans.puba(i);
        }
    }

    cout << szof(ans) << endl;

    for (int i = 0; i < szof(ans); ++i) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}