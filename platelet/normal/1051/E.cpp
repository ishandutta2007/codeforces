#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 1e6 + 5, P = 998244353;

int z[N], zL[N], zR[N];
char A[N], L[N], R[N];
int f[N], g[N];

void Z(char s[], char t[], int a[]) {
    int l = 0, r = 0;
    for(int i = 0; t[i]; i++) {
        int& j = a[i] = i <= r ? min(z[i - l], r - i + 1) : 0;
        while(s[j] && t[i + j] == s[j]) j++;
        if(i + j >= r) l = i, r = i + j - 1;
    }
}
int add(int a, int b) { return a += b, a < P ? a : a - P; }
int sub(int a, int b) { return a -= b, a < 0 ? a + P : a; }

int main() {
    scanf("%s%s%s", A, L, R);
    int lA = strlen(A), lL = strlen(L), lR = strlen(R);
    Z(L, L + 1, z + 1), Z(L, A, zL), Z(R, R + 1, z + 1), Z(R, A, zR);
    f[0] = 1, g[0] = A[0] > 48;
    rep(i, 1, lA) {
        auto calc = [&](int n, char s[], int z[], bool eq) {
            int res = sub(g[i - 1], i >= n ? g[i - n] : 0);
            if(i >= n && A[i - n] > 48) {
                int len = z[i - n];
                if((len == n && eq) || (len < n && A[i - n + len] < s[len] + eq))
                    res = add(res, f[i - n]);
            }
            if(A[i - 1] == 48 && (eq || n > 1 || s[0] > 48))
                res = add(res, f[i - 1]);
            return res;
        };
        f[i] = sub(calc(lR, R, zR, 1), calc(lL, L, zL, 0));
        g[i] = add(g[i - 1], A[i] > 48 ? f[i] : 0);
    }
    cout << f[lA];
}