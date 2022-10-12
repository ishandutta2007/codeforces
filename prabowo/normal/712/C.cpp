#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    scanf ("%d %d", &y, &x);
    
    int a[3];
    a[0] = a[1] = a[2] = x;
    
    int ans = 0;
    while (a[0] < y || a[1] < y || a[2] < y) {        
        int tmp = a[1] + a[2] - 1;
        a[0] = a[1];
        a[1] = a[2];
        a[2] = tmp;
        
        ans++;
    }
    
    printf ("%d\n", ans);

    return 0;
}