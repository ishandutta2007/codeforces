#include <bits/stdc++.h>
#define Task "D"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

int n;
long long Res, MaxMax, MaxMin, x;

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        if(i == 1 || Res + x > MaxMax)
            MaxMax = Res + x;
        if(i == 1|| Res - x > MaxMin)
            MaxMin = Res - x;
        Res = max(Res, MaxMax - x);
        Res = max(Res, MaxMin + x);
    }
    cout << Res;
    return 0;
}