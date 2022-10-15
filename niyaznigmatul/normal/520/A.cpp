#include <bits/stdc++.h>

using namespace std;

int get(int c) {
    if (c >= 'A' && c <= 'Z') c -= 'A', c += 'a';
    return c - 'a';
}

int z[42];

int main() {
    int n;
    scanf("%d", &n);
    int c = getchar();
    while (c <= 32) c = getchar();
    for (int i = 0; i < n; i++) z[get(c)]++, c = getchar();
    int cn = 0;
    for (int i = 0; i < 26; i++) if (z[i] > 0) ++cn;
    puts(cn == 26 ? "YES" : "NO");
}