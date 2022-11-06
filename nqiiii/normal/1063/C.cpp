#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
int l = 1, r = 1e9;
int res1;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n / 2; ++i) {
        int mid = (l + r) >> 1;
        printf("%d %d\n", mid, 0);
        fflush(stdout);
        string s; cin >> s;
        if (s == "black") l = mid + 1;
        else r = mid - 1;
    }
    res1 = l;
    l = 1; r = 1e9;
    for (int i = n / 2 + 1; i <= n; ++i) {
        int mid = (l + r) >> 1;
        printf("%d %d\n", 0, mid);
        fflush(stdout);
        string s; cin >> s;
        if (s == "black") l = mid + 1;
        else r = mid - 1;
    }
    printf("%d %d %d %d", res1, 0, 0, l);
}