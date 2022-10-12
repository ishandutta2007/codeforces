#include <bits/stdc++.h>
using namespace std;

map<int, int> dp[66];
int f(int x, int mask) {
    if (x == 0) return 0;
    if (dp[x].find(mask) != dp[x].end()) return dp[x][mask];
    
    int nim[66];
    for (int i=0; i<x+5; i++) nim[i] = 0;
    for (int i=1; i<=x; i++) {
        if ((i <= 30) && (mask >> i & 1)) continue;
        nim[f(x-i, mask | 1 << i)] = 1;
    }
    
    int mex = 0;
    while (nim[mex++]);
    return dp[x][mask] = mex-1;
}

int main() {
    
    clock_t t = clock();
    vector<int> nims;
    for (int i=0; i<=60; i++) nims.push_back(f(i, 0));
    cerr << (double) (clock() - t) / CLOCKS_PER_SEC << endl;
    
    int n;
    scanf("%d", &n);
    int nim = 0, s;
    for (int i=0; i<n; i++) {
        scanf("%d", &s);
        nim ^= nims[s];
    }
    
    if (nim) printf("NO\n");
    else printf("YES\n");
    return 0;
}