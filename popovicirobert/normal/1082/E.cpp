#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 5e5 + 5;

int arr[MAXN + 1], cnt_l[MAXN + 1], cnt_r[MAXN + 1];
vector <int> pos[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, c;
    ios::sync_with_stdio(false);
    cin >> n >> c;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        cnt_l[i] = cnt_l[i - 1] + (arr[i] == c);
        pos[arr[i]].push_back(i);
    }
    for(i = n; i >= 1; i--) {
        cnt_r[i] = cnt_r[i + 1] + (arr[i] == c);
    }
    int ans = 0;
    for(i = 1; i <= MAXN; i++) {
        int mx = -2 * MAXN;
        int p = 0;
        for(auto it : pos[i]) {
            mx = max(mx, cnt_l[it - 1] - p + 1);
            ans = max(ans, cnt_r[it + 1] + p + mx);
            p++;
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}