#include <bits/stdc++.h>

#define err(...) //fprintf(stderr, __VA_ARGS__), fflush(stdout)
typedef long long ll;

using namespace std;

const int dd = (int)3e5 + 7;

int main() {
    int n, t, k, d;
    scanf("%d %d %d %d", &n, &t, &k, &d);
    int tim1 = (n + k - 1) / k * t;
    if (tim1 - t > d) puts("YES");
    else puts("NO");
    return 0;
}