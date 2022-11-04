#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

int cnt[101];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 0; i <= n; i++) {
        for(j = i + 1; j <= n; j++) {
            for(int p = i; p < j; p++) {
                cnt[p]++;
            }
        }
    }
    int ans = 0;
    for(i = 0; i <= n; i++) {
        ans = max(ans, cnt[i]);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}