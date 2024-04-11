#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 6

using namespace std;

ll cst[31];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, i, l;
    ios::sync_with_stdio(false);
    cin >> n >> l;
    for(i = 0; i <= 30; i++) {
        cst[i] = (1LL << 60);
    }
    for(i = 0; i < n; i++) {
        cin >> cst[i];
    }
    for(i = 1; i <= 30; i++) {
        cst[i] = min(cst[i - 1] * 2, cst[i]);
    }
    ll ans = 0;
    for(i = 0; i <= 30; i++) {
        if(l & (1 << i))
            ans += cst[i];
    }
    for(i = 31; i > 0; i--) {
        ll val = 0;
        if((l & (1 << (i - 1))) == 0) {
            for(int j = 30; j >= i; j--) {
                if(l & (1 << j))
                    val += cst[j];
            }
            val += cst[i - 1];
             ans = min(ans, val);
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}