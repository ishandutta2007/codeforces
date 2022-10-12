#include <bits/stdc++.h>
using namespace std;

int n;
int h[100002];
int tower[100002];

int main (){
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &h[i]);

    int now = 0;
    for (int i=0; i<n; i++) {
        now = min(now+1, h[i]);
        tower[i] = now;
    }

    now = 0;
    for (int i=n; i>0; i--) {
        now = min(now+1, h[i-1]);
        tower[i-1] = min(tower[i-1], now);
    }

    int ans = 0;
    for (int i=0; i<n; i++) ans = max(ans, tower[i]);

    printf("%d\n", ans);

    return 0;
}