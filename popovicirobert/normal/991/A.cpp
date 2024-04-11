#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int a, b, c, n;
    ios::sync_with_stdio(false);
    cin >> a >> b >> c >> n;
    int ans = n - (a + b - c);
    if(ans > n || ans <= 0 || min(a, b) < c)
        cout << -1;
    else
        cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}