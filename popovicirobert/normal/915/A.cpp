#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 22

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int ans = 0;
    for(i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(k % x == 0)
            ans = max(ans, x);
    }
    if(ans == 0) {
        cout << -1;
        return 0;
    }
    cout << k / ans;
    //cin.close();
    //cout.close();
    return 0;
}