#include <bits/stdc++.h>
using namespace std;

int n, k, x;
int cnt[2][1024];

int main() {
    scanf("%d %d %d", &n, &k, &x);
    
    int a;
    for (int i=0; i<n; i++) {
        scanf("%d", &a);
        ++cnt[0][a];
    }
    
    for (int i=0; i<k; i++) {        
        int cur = 0;
        for (int j=0; j<1024; j++) cnt[i+1&1][j] = 0;
        for (int j=0; j<1024; j++) {            
            if (cnt[i&1][j] & 1) {
                if (cur & 1) {
                    cnt[i+1&1][j ^ x] += cnt[i&1][j] >> 1;
                    cnt[i+1&1][j] += cnt[i&1][j] + 1 >> 1;
                } else {
                    cnt[i+1&1][j ^ x] += cnt[i&1][j] + 1 >> 1;
                    cnt[i+1&1][j] += cnt[i&1][j] >> 1;
                }
            } else {
                cnt[i+1&1][j ^ x] += cnt[i&1][j] >> 1;
                cnt[i+1&1][j] += cnt[i&1][j] >> 1;
            }
            
            cur += cnt[i&1][j];
        }
    }
    
    int mini = 1024, maks = 0;
    for (int i=0; i<1024; i++) if (cnt[k&1][i]) maks = i;
    for (int i=1023; i>=0; i--) if (cnt[k&1][i]) mini = i;
    printf("%d %d\n", maks, mini);
    return 0;
}