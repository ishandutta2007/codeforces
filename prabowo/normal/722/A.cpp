#include <bits/stdc++.h>
using namespace std;

int diff(int x, int y) {
    return ((x % 10) != (y % 10)) + (x / 10 != y / 10);
}

int main() {
    int f;
    scanf ("%d", &f);
    int h, m;
    scanf ("%d:%d", &h, &m);
    
    if (f == 12) {
        int hans, mans;
        int mini =100;
        for (int H = 1; H <= 12; H++) {
            for (int M = 0; M < 60; M++) {
                if (diff(M, m) + diff(H, h) < mini) {
                    mini = diff(M, m) + diff(H, h);
                    hans = H;
                    mans = M;
                }
            }
        }
        
        printf ("%02d:%02d\n", hans, mans);
    } else {
        
        int hans, mans;
        int mini =100;
        for (int H = 0; H <= 23; H++) {
            for (int M = 0; M < 60; M++) {
                if (diff(M, m) + diff(H, h) < mini) {
                    mini = diff(M, m) + diff(H, h);
                    hans = H;
                    mans = M;
                }
            }
        }
        
        printf ("%02d:%02d\n", hans, mans);
    }
    return 0;
}