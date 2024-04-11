#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf ("%d", &n);
    
    set <int> S;
    int y;
    for (int i=0; i<n; i++) {
        scanf ("%d", &y);
        S.insert(y);
    }
    
    while (1) {
        int maks = *S.rbegin();
        S.erase(maks);
        
        int baru = maks;
        for (int i=maks>>1; i; i>>=1) {
            if (S.count(i));
            else {
                baru = i;
                break;
            }
        }
        
        S.insert(baru);
        if (baru == maks) break;
    }
    
    for (set<int>::iterator it = S.begin(); it != S.end(); ++it) printf ("%d ", *it); printf ("\n");
    return 0;
}