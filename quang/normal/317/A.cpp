#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N

using namespace std;

long long x ,y ,m;

int main() {
   // fi, fo;
    scanf("%I64d%I64d%I64d", &x, &y, &m);
    if(x > y) swap(x, y);
    if(y >= m) {
        cout << 0;
        return 0;
    }
    if(y <= 0) {
        cout << -1;
        return 0;
    }
    long long res = 0;
    if(x < 0) {
        res += (-x) / y + 1;
        x += res * y;
    }
    while(y < m) {
        res++;
        x += y;
        swap(x, y);
    }
    printf("%I64d", res);
    return 0;
}