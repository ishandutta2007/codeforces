#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 217
// 44

using namespace std;


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, ans = 0;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        if(2 * i <= n && (n - i) % i == 0)
            ans++;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}