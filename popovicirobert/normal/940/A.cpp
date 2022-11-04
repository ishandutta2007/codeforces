#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 206
// 44

using namespace std;

int v[101];

int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int i, j, n, d;
    ios::sync_with_stdio(false);
    cin >> n >> d;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v + 1, v + n + 1);
    int ans = 0;
    for(i = 1; i <= n; i++) {
        for(j = i; j <= n; j++) {
            if(v[j] - v[i] <= d) {
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << n - ans;
    //cin.close();
    //cout.close();
    return 0;
}