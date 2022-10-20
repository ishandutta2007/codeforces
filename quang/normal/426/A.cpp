#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N

using namespace std;

int n, s ,sum, gtmax;

int main() {
    //fi, fo;
    scanf("%d%d", &n, &s);
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        sum += x;
        gtmax = max(gtmax, x);
    }
    cout << ( (sum - gtmax <= s)? "YES" : "NO");
    return 0;
}