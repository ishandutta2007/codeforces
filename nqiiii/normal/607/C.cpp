#include <bits/stdc++.h>
using namespace std;
const int maxN = 2000000;

void Read(char &c) {
    c = getchar();
    while (!isgraph(c)) c = getchar();
}
char a[maxN + 10];
int n, nxt[maxN + 10];

int main() {
    scanf("%d", &n); 
    for (int i = n - 1; i >= 1; --i) {
        Read(a[i]);
        if (a[i] == 'W') a[i] = 'E';
        else if (a[i] == 'E') a[i] = 'W';
        else if (a[i] == 'S') a[i] = 'N';
        else if (a[i] == 'N') a[i] = 'S';
    }
    for (int i = n + 1; i <= n * 2 - 1; ++i) Read(a[i]);
    for (int i = 2; i <= n * 2 - 1; ++i) {
        nxt[i] = nxt[i - 1];
        while (nxt[i] && a[i] != a[nxt[i] + 1]) nxt[i] = nxt[nxt[i]];
        nxt[i] += a[i] == a[nxt[i] + 1];
    }
    printf(nxt[n * 2 - 1] ? "NO" : "YES");
}