#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long
#define db double
#define mp make_pair
const int N = 4194303 + 7;
int n, m, dp[N], a[N], ans;
int main() {
    scanf("%d", &n);
    L(i, 1, n) scanf("%d", &a[i]), dp[a[i]] = a[i];
    L(j, 0, 21) L(i, 0, 4194303) 
        if((i >> j) & 1) 
            if(dp[i ^ (1 << j)]) dp[i] = dp[i ^ (1 << j)];
    L(i, 1, n) {
        int pp = dp[4194303 ^ a[i]];
        if(pp) printf("%d ", pp);
        else printf("-1 ");
    }
    puts("");
    return 0;
}