#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 1000010

using namespace std;

int n, res;
int p[N], Xor[N];

int main() {
    //fi, fo;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", p + i);
    Xor[0] = 0;
    for(int i = 1; i <= n; i++) Xor[i] = Xor[i - 1] ^ i;
    for(int i = 1; i <= n; i++) {
        int x = n / i;
        int y = n % i;
        if(x % 2) res = res ^ Xor[i - 1];
        res = res ^ Xor[y] ^ p[i];
    }
    cout << res;
    return 0;
}