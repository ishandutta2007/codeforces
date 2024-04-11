#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e2+10, MOD = 1e9+7; 

int n, col[MAXN][MAXN];
bool done(bool parity) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (((i+j)&1) == parity && col[i][j] == -1) return 0;
        }
    }
    return 1;
}
ar<int, 2> get(bool parity) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (((i+j)&1) == parity && col[i][j] == -1) return {i, j};
        }
    }
    return {-1, -1};
}
void play(bool parity, int color) {
    assert(!done(parity));
    auto [i, j] = get(parity);
    col[i][j] = color;
    cout << color << ' ' << i+1 << ' ' << j+1 << endl;
}
void solve(){
    cin >> n;
    memset(col, -1, sizeof(col));
    for (int i = 0; i < n*n; i++) {
        int a; cin >> a;
        if (a == 1) {
            if (done(1)) play(0, 3);
            else play(1, 2);
        } 
        if (a == 2) {
            if (done(0)) play(1, 3);
            else play(0, 1);
        }
        if (a == 3) {
            if (!done(0)) play(0, 1);
            else play(1, 2);
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}