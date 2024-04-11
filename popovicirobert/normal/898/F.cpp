#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 1e6;

string str;

const int B = 10;
const int MOD1 = 666013;
const int MOD2 = 666019;

int pw1[MAXN + 1], pw2[MAXN + 1];
int v1[MAXN + 1], v2[MAXN + 1];

inline int mod1(int x) {
    if(x >= MOD1)
        x -= MOD1;
    return x;
}

inline int mod2(int x) {
    if(x >= MOD2)
        x -= MOD2;
    return x;
}

inline int get1(int l, int r) {
    return mod1(v1[r] - (1LL * v1[l - 1] * pw1[r - l + 1]) % MOD1 + MOD1);
}

inline int get2(int l, int r) {
    return mod2(v2[r] - (1LL * v2[l - 1] * pw2[r - l + 1]) % MOD2 + MOD2);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> str;
    n = str.size();
    str = " " + str;
    pw1[0] = pw2[0] = 1;
    for(i = 1; i <= n; i++) {
        str[i] -= '0';
        v1[i] = (1LL * v1[i - 1] * B + str[i]) % MOD1;
        pw1[i] = (pw1[i - 1] * B) % MOD1;
        v2[i] = (1LL * v2[i - 1] * B + str[i]) % MOD2;
        pw2[i] = (pw2[i - 1] * B) % MOD2;
    }
    if(str[1] == 0) {
        cout << 0 << "+";
        int len = (n - 1) / 2;
        for(i = 1; i <= len; i++) {
            cout << (int) str[i + 1];
        }
        cout << "=";
        for(i = 1; i <= len; i++) {
            cout << (int) str[i + len + 1];
        }
        return 0;
    }
    int pos1 = 0, pos2 = 0;
    for(i = 2; i < n; i++) {
        int len = n - i;
        if(i >= len && str[i + 1] != 0) {
            if(mod1(get1(1, len - 1) + get1(len, i)) == get1(i + 1, n) && mod2(get2(1, len - 1) + get2(len, i)) == get2(i + 1, n)) {
                if(str[len] != 0 || len == i) {
                    pos1 = len - 1;
                    pos2 = i;
                    break;
                }
            }
            if(len + 1 <= i && mod1(get1(1, len) + get1(len + 1, i)) == get1(i + 1, n) && mod2(get2(1, len) + get2(len + 1, i)) == get2(i + 1, n)) {
                if(str[len + 1] != 0 || i == len + 1) {
                    pos1 = len;
                    pos2 = i;
                    break;
                }
            }
            if(len >= 1 && mod1(get1(1, i - len) + get1(i - len + 1, i)) == get1(i + 1, n) && mod2(get2(1, i - len) + get2(i - len + 1, i)) == get2(i + 1, n)) {
                if(str[i - len + 1] != 0 || len == 1) {
                    pos1 = i - len;
                    pos2 = i;
                    break;
                }
            }
            if(len > 1 && mod1(get1(1, i - len + 1) + get1(i - len + 2, i)) == get1(i + 1, n) && mod2(get2(1, i - len + 1) + get2(i - len + 2, i)) == get2(i + 1, n)) {
                if(str[i - len + 2] != 0 || len == 2) {
                    pos1 = i - len + 1;
                    pos2 = i;
                    break;
                }
            }
        }
    }
    for(i = 1; i <= pos1; i++) {
        cout << (int) str[i];
    }
    cout << "+";
    for(i = pos1 + 1; i <= pos2; i++) {
        cout << (int) str[i];
    }
    cout << "=";
    for(i = pos2 + 1; i <= n; i++) {
        cout << (int) str[i];
    }
    //cin.close();
    //cout.close();
    return 0;
}