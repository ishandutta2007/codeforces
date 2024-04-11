#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf ("%d", &n);
    
    int a[n];
    for (int i=0; i<n; i++) scanf ("%d", a + i);
    sort (a, a + n);
    
    int mex = 1;
    for (int i=0; i<n; i++) {
        if (mex <= a[i]) mex++;
    }
    printf ("%d\n", mex);
    return 0;
}