#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;
const int MAXM = (int) 1e6;
const int MOD1 = 666013;
const int MOD2 = 666019;
const int B1 = 31;
const int B2 = 37;

char str1[MAXN + 1], str2[MAXM + 1];

inline int mod(int x, int md) {
    if(x >= md)
        x -= md;
    return x;
}

int hsh1[MAXM + 1], pw1[MAXM + 1];
int hsh2[MAXM + 1], pw2[MAXM + 1];

inline int get1(int l, int r) {
    return mod(hsh1[r] - (1LL * hsh1[l - 1] * pw1[r - l + 1]) % MOD1 + MOD1, MOD1);
}

inline int get2(int l, int r) {
    return mod(hsh2[r] - (1LL * hsh2[l - 1] * pw2[r - l + 1]) % MOD2 + MOD2, MOD2);
}

inline pair <int, int> get(int l, int r) {
    return {get1(l, r), get2(l, r)};
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> str1 + 1 >> str2 + 1;
    int n = strlen(str1 + 1), m = strlen(str2 + 1);
    int cnt0 = 0, cnt1 = 0;
    for(i = 1; i <= n; i++) {
        if(str1[i] == '1') {
            cnt1++;
        }
        else {
            cnt0++;
        }
    }
    pw1[0] = pw2[0] = 1;
    for(i = 1; i <= m; i++) {
        hsh1[i] = (hsh1[i - 1] * B1 + str2[i] - 'a' + 1) % MOD1;
        pw1[i] = (pw1[i - 1] * B1) % MOD1;
        hsh2[i] = (hsh2[i - 1] * B2 + str2[i] - 'a' + 1) % MOD2;
        pw2[i] = (pw2[i - 1] * B2) % MOD2;
    }
    ll ans = 0;
    for(int l0 = 1; l0 <= m; l0++) {
        ll cur = m - 1LL * l0 * cnt0;
        if(cur <= 0) {
            break;
        }
        if(cur % cnt1 > 0) {
            continue;
        }
        int l1 = cur / cnt1;
        pair <ull, ull> val0, val1;
        bool ok0 = 0, ok1 = 0;
        int pos = 1;
        bool flag = 1;
        i = 1;
        for(int pos = 1; pos <= n; pos++) {
            if(str1[pos] == '0') {
                pair <ull, ull> val = get(i, i + l0 - 1);
                if(ok0 == 0) {
                    val0 = val;
                    ok0 = 1;
                }
                else if(val0.first != val.first || val0.second != val.second) {
                    flag = 0;
                    break;
                }
                i += l0;
            }
            else {
                pair <ull, ull> val = get(i, i + l1 - 1);
                if(ok1 == 0) {
                    val1 = val;
                    ok1 = 1;
                }
                else if(val1.first != val.first || val.second != val1.second) {
                    flag = 0;
                    break;
                }
                i += l1;
            }
        }
        if(flag) {
            if(val0.first != val1.first || val0.second != val1.second) {
                ans++;
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}