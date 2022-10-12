#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[111];

int main() {
    
    scanf ("%d %d", &n, &k);
    
    for (int i=0; i<n; i++) scanf ("%d", a + i);
    
    int ans = 0;
    for (int i=0; i<k; i++) {
        int cnt0 = 0;
        int cnt1 = 0;
        
        for (int j=i; j<n; j+=k) {
            if (a[j] == 1) cnt0++;
            else cnt1++;
        }
        
        ans += min(cnt0, cnt1);
    }
    
    
    printf ("%d\n", ans);
    
    return 0;
}