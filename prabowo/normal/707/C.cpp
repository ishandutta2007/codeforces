#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    scanf ("%I64d", &n);
    
    if (n <= 2) printf ("-1\n");
    else if (n & 1) printf ("%I64d %I64d\n", n*n - 1 >> 1, n*n + 1 >> 1);
    else printf ("%I64d %I64d\n", n*n/4 - 1, n*n/4 + 1);
    return 0;
}