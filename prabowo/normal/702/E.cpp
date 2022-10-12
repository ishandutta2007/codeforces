#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
const int LOGK = 41;

int par[LOGK][N];
long long sum[LOGK][N];
int mini[LOGK][N];

int main() {
    int n; long long k;
    scanf ("%d %lld", &n, &k);
    
    for (int i=0; i<n; i++) 
        scanf ("%d", &par[0][i]);
    
    for (int i=0; i<n; i++) 
        scanf ("%d", &sum[0][i]),
        mini[0][i] = sum[0][i];
            
    for (int i=1; i<LOGK; i++) {
        for (int j=0; j<n; j++) {
            par[i][j] = par[i-1][par[i-1][j]];
            sum[i][j] = sum[i-1][j] + sum[i-1][par[i-1][j]];
            mini[i][j] = min(mini[i-1][j], mini[i-1][par[i-1][j]]);
        }
    }
    
    for (int i=0; i<n; i++) {
        long long s = 0;
        int m = 1000000000;
        long long _k = k;
        int cur = i;
        
        for (int j = 0; _k; _k >>= 1, j++) {
            if (_k & 1) {
                s += sum[j][cur];
                m = min(m, mini[j][cur]);
                cur = par[j][cur];
            }
        }   
        
        printf ("%lld %d\n", s, m);
    }   
    
    return 0;
}