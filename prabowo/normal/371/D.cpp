#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int n, m;
int a[N];
int isi[N];

int main() {
    set <int> s;
    
    scanf ("%d", &n);
    for (int i=0; i<n; i++) {
        scanf ("%d", a + i);
        s.insert(i);
    }
    
    scanf ("%d", &m);
    while (m--) {
        int q;
        scanf ("%d", &q);
        
        if (q == 1) {
            int x, p;
            scanf ("%d %d", &p, &x);
            p--;
            
            do {
                set <int>::iterator it = s.lower_bound(p);
                if (it == s.end()) break;
                
                int tmp = min(a[*it] - isi[*it], x);
                isi[*it] += tmp;
                x -= tmp;
                
                if (isi[*it] == a[*it]) s.erase(it);
            } while (x);
        } else {
            int k;
            scanf ("%d", &k);
            printf ("%d\n", isi[k-1]);
        }
    }
    
    
    return 0;
}