#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int n, m;
bool r[N], c[N];

int main () {
    scanf ("%d %d", &n, &m);
    
    int x, y;
    long long att = 1LL * n * n;
    
    int rr = n, cc = n;
    while (m--) {
        scanf ("%d %d", &x, &y);
        x--, y--;
        
        if (r[x] && c[y]);
        else if (r[x]) {
            att -= rr;
            cc--;
        } else if (c[y]) {
            att -= cc;
            rr--;
        } else {
            att -= cc--;
            att -= rr--;
            att++;
        }
        
        r[x] = c[y] = 1;
        printf ("%I64d ", att);
    }
    printf ("\n");
    
    
    return 0;
}