#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

bool inRange(int x, int l, int r) {
    return x >= l && x <= r;
}

bool check(pii x, pii y) {
    if (inRange(x.first, y.first, y.second)) return 0;
    if (inRange(x.second, y.first, y.second)) return 0;
    if (inRange(y.first, x.first, x.second)) return 0;
    if (inRange(y.second, x.first, x.second)) return 0;
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    set<pii> S;
    
    int L, R;
    for (int i=0; i<n; i++) {
        scanf("%d %d", &L, &R);
        R += L - 1;
        
        bool ok = 1;
        for(pii s: S) {
            ok &= check({L, R}, s);            
        }
        
        if (ok) {        
            S.insert({L, R});
            printf("%d %d\n", L, R);
        } else {
            int cur = 1;
            
            bool ok = 0;
            for (pii s: S) {
                if (s.first - cur >= R - L + 1) {
                    S.insert({cur, cur + (R - L)});
                    printf("%d %d\n", cur, cur + (R - L));
                    ok = 1;
                    break;
                }
                
                cur = s.second + 1;
            }
            
            if (!ok) {
                S.insert({cur, cur + (R - L)});
                printf("%d %d\n", cur, cur + R - L);
            }
        }
    }
    return 0;
}