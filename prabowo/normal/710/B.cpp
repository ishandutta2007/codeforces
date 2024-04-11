#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf ("%d", &n);
    int x[n];
    for (int i=0; i<n; i++) scanf ("%d", x + i);
    
    sort (x, x + n);
    printf ("%d\n", x[(n >> 1) - (n + 1 & 1)]);
    return 0;
}