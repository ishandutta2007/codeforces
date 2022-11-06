#include <bits/stdc++.h>
using namespace std;
const int maxN = 2000000;
int p, q;
bool nPrm[maxN + 10];
int prm[maxN + 10], prmCnt;
int pi, rub;
int a[maxN + 10], aCnt;
int ans;

void PreWork() {
    nPrm[1] = 1;
    for (int i = 2; i <= maxN; ++i) {
        if (!nPrm[i]) prm[++prmCnt] = i;
        for (int j = 1; j <= prmCnt && i * prm[j] <= maxN; ++j) {
            nPrm[i * prm[j]] = 1;
            if (i % prm[j] == 0) break;
        }
    }
}

bool Check(int v) {
    aCnt = 0;
    while (v) {
        a[++aCnt] = v % 10; v /= 10;
    }
    for (int i = 1; i * 2 <= aCnt; ++i)
        if (a[i] != a[aCnt + 1 - i]) return 0;
    return 1;
}

int main() {
    PreWork();
    scanf("%d%d", &p, &q);
    for (int i = 1; i <= maxN; ++i) {
        pi += !nPrm[i];
        rub += Check(i);
        if (1ll * pi * q <= 1ll * rub * p) ans = i;
    }
    if (ans) printf("%d", ans);
    else printf("Palindromic tree is better than splay tree");
}