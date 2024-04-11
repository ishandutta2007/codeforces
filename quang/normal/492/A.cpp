#include <bits/stdc++.h>
#define Task "A"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

int n, tr = 0;

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n;
    int lv = 0;
    while(1) {
        lv++;
        tr += lv * (lv + 1) / 2;
        if(tr > n) break;
    }
    cout << lv - 1;
    return 0;
}