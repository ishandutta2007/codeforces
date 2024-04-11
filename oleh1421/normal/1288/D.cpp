#include <bits/stdc++.h>
 
using namespace std;
const long long M = 1e9 + 7;
 
int n, m;
int a[300010][10];
int x, y;
int id[1000];
 
bool ok(int q) {
    for(int i = 0; i < (1 << m); i++) {
        id[i] = -1;
    }
    for(int i = 0; i < n; i++) {
        int mask = 0;
        for(int j = 0; j < m; j++) {
            if(a[i][j] >= q) {
                mask |= (1 << j);
            }
        }
        id[mask] = i;
    }
    for(int i = 0; i < (1 << m); i++) {
        for(int j = 0; j < (1 << m); j++) {
            if((i | j) + 1 == (1 << m) && id[i] != -1 && id[j] != -1) {
                x = id[i];
                y = id[j];
                return true;
            }
        }
    }
    
    return false;
} 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    int l = 0, r = 1e9;
    while(l < r) {
        int m = (l + r + 1) / 2;
        if(ok(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    ok(l);
    cout << x+1 << " " << y+1;
}