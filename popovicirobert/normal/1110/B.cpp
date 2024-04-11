#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

int b[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector <int> ord;
    for(i = 2; i <= n; i++) {
        ord.push_back(b[i] - b[i - 1]);
    }
    sort(ord.begin(), ord.end(), greater<int>());
    int ans = b[n] - b[1] + 1;
    if(k >= n) {
        ans = n;
    }
    else {
        for(i = 0; i < k - 1; i++) {
            ans -= ord[i] - 1;
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}