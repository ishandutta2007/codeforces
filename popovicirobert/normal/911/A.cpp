#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 1e5;

int v[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    int mn = (int) 2e9;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
        if(v[i] < mn)
            mn = v[i];
    }
    int pos = -n;
    int ans = 2 * n;
    for(i = 1; i <= n; i++) {
        if(v[i] == mn) {
            ans = min(ans, i - pos);
            pos = i;
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}