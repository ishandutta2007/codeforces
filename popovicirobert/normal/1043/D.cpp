#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;
const int MAXM = 10;

int arr[MAXM + 1][MAXN + 1], pos[MAXM + 1][MAXN + 1];
int m;

inline bool check(int a, int b) {
    int i;
    for(i = 1; i <= m; i++) {
        if(pos[i][arr[1][b]] - pos[i][arr[1][a]] != b - a) {
            return 0;
        }
    }
    return 1;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= m; i++) {
        for(j = 1; j <= n; j++) {
            cin >> arr[i][j];
            pos[i][arr[i][j]] = j;
        }
    }
    ll ans = 0;
    i = 1;
    while(i <= n) {
        j = i;
        while(j <= n && check(i, j)) {
            j++;
        }
        //cerr << i << " " << j << "\n";
        ans += 1LL * (j - i) * (j - i + 1) / 2;
        i = j;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}