#include <bits/stdc++.h>
using namespace std;

void c(int &x, int &ca, int &cb, int &cc) {    
    while (x % 2 == 0) x /= 2, ca++;
    while (x % 3 == 0) x /= 3, cb++;
    while (x % 5 == 0) x /= 5, cc++;    
}

int aa, ab, ac;
int ba, bb, bc;

int main() {
    int a, b;
    scanf ("%d %d", &a, &b);
    
    c(a, aa, ab, ac);
    c(b, ba, bb, bc);
    
    if (a != b) return 0 * printf ("-1\n");
    printf ("%d\n", abs(aa - ba) + abs(ab - bb) + abs(ac - bc));
    
    return 0;
}