#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[100002];
    gets(s);
    
    int n = strlen(s);
    if (n & 1) return 0 * printf ("-1\n");
    
    int u, l, r, d;
    u = l = r = d = 0;
    
    for (int i=0; i<n; i++) {
        if (s[i] == 'U') u++;
        if (s[i] == 'D') d++;
        if (s[i] == 'L') l++;
        if (s[i] == 'R') r++;
    }
    
    printf ("%d\n", abs(l - r) + abs(u - d) >> 1);
    
    return 0;
}