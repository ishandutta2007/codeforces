#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 998244353;

int mex(vector<int> v) {
    sort(v.begin(), v.end());
    for (int i = 0; i < sz(v); i++) if (v[i] != i) return i;
    return sz(v);
}

bool bad[MAXN];

const int MAXL = 30;
int grundy[MAXL]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};

void solve(){
    int n; cin >> n;

    int x = 1;
    int taken = 0;

    const int SQRT = min(n, int(sqrt(n))+1);
    for (int i = 2; i <= SQRT; i++) if (!bad[i]) {
        int cnt_pow = 0;
        for (ll j = i; j <= n; j *= i) {
            cnt_pow++;
            if (j <= SQRT) bad[j] = 1;
            else taken++;
        }

        x ^= grundy[cnt_pow];
    }
    int big = n-SQRT;
    int other = big - taken;
    if (other&1) x ^= grundy[1];

    cout << (x ? "Vasya\n" : "Petya\n");
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}