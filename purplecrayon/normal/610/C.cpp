#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = (1<<9)+10, MOD = 1e9+7;

//it's basically xor, you need the xor of a and b to have exactly 2^(k-1) one bits

int n;
void solve(){
    cin >> n; n = 1<<n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int c = i|j;
            if ((__builtin_popcount(c)&1)) cout << '+';
            else cout << '*';
        }
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}