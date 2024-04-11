#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf ("%d", &n);
    
    bool num[n][n];
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) num[i][j] = 0;
    
    for (int i=0; i<n; i++) {
        num[i][n>>1] = num[n>>1][i] = 1;
    }
    
    int odd = n * 2 - 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (num[i][j]) continue;
            if (odd <= (n * n >> 1)) {
                num[i][j] = 1;
                num[n-i-1][j] = 1;
                num[i][n-j-1] = 1;
                num[n-i-1][n-j-1] = 1;
                odd += 4;
            }
        }
    }
    
    odd = -1;
    int even = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (num[i][j]) printf ("%d ", odd += 2);
            else printf ("%d ", even += 2);
        }
        printf ("\n");
    }
    
    return 0;
}