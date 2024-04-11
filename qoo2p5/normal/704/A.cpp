#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 3e5 + 123;

int n, q;
set<int> a[N];
set<int> w;

int main() {
    scanf("%d%d", &n, &q);
    int last = 0;
    
    for (int i = 0; i < q; i++) {
        int t, x;
        scanf("%d%d", &t, &x);
        
        if (t == 1) {
            w.insert(last);
            a[x].insert(last);
            last++;
        } else if (t == 2) {
            for (int j : a[x]) {
                if (w.count(j)) {
                    w.erase(j);
                }
            }
            
            a[x].clear();
        } else if (t == 3) {
            while (!w.empty() && *w.begin() < x) {
                w.erase(*w.begin());
            }
        }
        
        printf("%d\n", (int) w.size());
    }
    
    return 0;
}