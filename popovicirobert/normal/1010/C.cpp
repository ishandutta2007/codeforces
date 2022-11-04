#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXK = (int) 1e5;

bool vis[MAXK + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int g = 0;
    for(i = 1; i <= n; i++) {
        int x;
        cin >> x;
        x %= k;
        g = __gcd(g, x);
    }
    int val = 0;
    int ans = 0;
    while(vis[val] == 0) {
        ans++;
        vis[val] = 1;
        val += g;
        val %= k;
    }
    cout << ans << "\n";
    for(i = 0; i < k; i++) {
        if(vis[i]) {
            cout << i << " ";
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}