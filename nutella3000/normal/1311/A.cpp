#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("no-stack-protector")

using namespace std;
const int inf = 1e9 + 7;
const int max_n = (1 << 19);




signed main() {
    //freopen("inpur.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int test;
    cin >> test;
    for(int i = 0;i < test;i++) {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        if (a == b) ans = 0;
        else if (a < b && a % 2 != b % 2) ans = 1;
        else if (a < b) ans = 2;
        else if (a % 2 == b % 2) ans = 1;
        else ans = 2;

        cout << ans << '\n';
    }
}