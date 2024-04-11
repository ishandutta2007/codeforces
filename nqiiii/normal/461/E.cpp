#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
const int maxL = 100000, maxC = 5000000;
const Long lim = 2e18;
Long n;
int l, ch[maxC + 10][4], ndCnt;
char s[maxL + 10];

Long Add(Long x, Long y) {
    if (x == -1 || y == -1) return -1;
    return x + y <= lim ? x + y : -1;
}

Long Cmp(Long x, Long y) {
    if (x == -1) return 0;
    if (y == -1) return 1;
    return x < y;
}
Long Min(Long x, Long y) {
    return Cmp(x, y) ? x : y;
}

struct Matrix {
    Long a[5][5];
}a, t;
Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix ans;
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= 4; ++j) {
            ans.a[i][j] = -1;
            for (int k = 1; k <= 4; ++k)
                ans.a[i][j] = Min(ans.a[i][j], Add(a.a[i][k], b.a[k][j]));
        }
    return ans;
}

void Dfs(int p, int st, int len) {
    for (int i = 0; i < 4; ++i)
        if (ch[p][i]) Dfs(ch[p][i], st ? st : i + 1, len + 1);
        else if (st) {
            a.a[st][i + 1] = Min(a.a[st][i + 1], len);
        }
}

Matrix Fpow(Matrix a, Long b) {
    Matrix ans = a; --b;
    while (b) {
        if (b % 2) ans = ans * a;
        b /= 2; a = a * a;
    }
    return ans;
}

bool Check(Long v) {
    t = Fpow(a, v);
    Long ans = -1;
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= 4; ++j)
            ans = Min(ans, t.a[i][j]);
    return !Cmp(ans, n);
}

int main() {
    scanf("%lld", &n);
    scanf("%s", s + 1);
    l = strlen(s + 1);
    for (int i = 1; i <= 30; ++i)
        for (int j = 1; j <= l - i + 1; ++j) {
            int t = 0;
            for (int k = j; k <= j + i - 1; ++k) {
                if (!ch[t][s[k] - 'A']) ch[t][s[k] - 'A'] = ++ndCnt;
                t = ch[t][s[k] - 'A'];
            }
        }
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= 4; ++j) a.a[i][j] = -1;
    Dfs(0, 0, 0);
    Long ls = 1, rs = n;
    while (ls != rs) {
        Long mid = (ls + rs) / 2;
        if (Check(mid)) rs = mid; else ls = mid + 1;
    }
    printf("%lld", ls);
}