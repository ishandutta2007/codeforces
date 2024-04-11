#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = 100;

int arr[MAXN + 1];
bool vis[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for(int b = 1; b <= n; b++) {
        memset(vis, 0, sizeof(vis));
        for(i = -n; i <= n; i++) {
            int cur = b + i * k;
            if(1 <= cur && cur <= n)
                vis[cur] = 1;
        }
        int cur = 0;
        for(i = 1; i <= n; i++) {
            if(vis[i] == 0) {
                cur += arr[i];
            }
        }
        ans = max(ans, abs(cur));
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}