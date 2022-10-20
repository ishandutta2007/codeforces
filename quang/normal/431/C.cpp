#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX 1000000007ll
#define N 220

using namespace std;

int n, k ,d;
long long a[N][2];

int main() {
   // fi, fo;
    scanf("%d%d%d", &n, &k, &d);
    memset(a, 0, sizeof(a));
    if(d > k){
        cout << 0;
        return 0;
    }
    a[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= min(i, k); j++) {
            if(j < d) a[i][0] = (a[i][0] + a[i - j][0]) % MAX;
            else a[i][1] = (a[i][1] + a[i - j][0]) % MAX;
            a[i][1] = (a[i][1] + a[i - j][1]) % MAX;
        }
    }
    cout << a[n][1];
    return 0;
}