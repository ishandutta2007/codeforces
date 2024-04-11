#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, a;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    map <int, int> fr[2];
    int s = 0;
    ll ans = 0;
    fr[0][0]++;
    for(i = 1; i <= n; i++) {
        cin >> a;
        s ^= a;
        ans += fr[i & 1][s];
        fr[i & 1][s]++;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}