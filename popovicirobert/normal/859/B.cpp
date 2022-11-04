#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    int ans = 4 * n;
    for(i = 1; i <= n; i++)
        ans = min(ans, 2 * (i + (n + i - 1) / i));
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}