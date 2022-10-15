#include <cstdio>
#include <algorithm>

using namespace std;

const int MOD1 = 1000000007;
const int MOD2 = 1000000009;
const int P = 239;

pair<int, int> z[1555 * 1555];
char s[12345], t[33];
int a[12345];

int main() {
    gets(s);
    gets(t);
    int n = 0;
    int m = 0;
    while (s[n]) ++n;
    while (t[m]) ++m;
    int k;
    scanf("%d", &k);
    for (int i = 0; i < n; i++) {
        a[i + 1] = 1 - (t[s[i] - 'a'] - '0');
    }
    a[0] = 0;
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    int cur = 0;
    for (int i = 0; i < n; i++) {
        long long h1 = 0;
        long long h2 = 0;
        for (int j = i; j < n; j++) {
            h1 = (h1 * P + s[j] - 'a' + 1) % MOD1;
            h2 = (h2 * P + s[j] - 'a' + 1) % MOD2;
            if (a[j + 1] - a[i] <= k) {
                z[cur++] = make_pair((int) h1, (int) h2);
            }
        }
    }
    sort(z, z + cur);
    int ans = 0;
    for (int i = 0; i < cur; i++) 
        if (i == 0 || z[i] != z[i - 1]) 
            ++ans;
    printf("%d\n", ans);
}