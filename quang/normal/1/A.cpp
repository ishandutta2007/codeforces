#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N

using namespace std;

long long n, m, a;

int main() {
    //fi, fo;
    scanf("%I64d%I64d%I64d", &n, &m, &a);
    long long aa = ceil(1.0 * n / a);
    long long bb = ceil(1.0 * m / a);
    cout << aa * bb;
    return 0;
}