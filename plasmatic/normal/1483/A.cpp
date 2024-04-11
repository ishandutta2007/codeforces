// ./a-basic-diplomacy.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 1e5 + 1;
int N, M;

void solve() {
    cin >> N >> M;
    vector<int> fre(N+1);
    vector<vector<int>> sel(M);
    for (auto i = 0; i < M; i++) {
        int n; cin >> n;
        for (auto j = 0; j < n; j++) {
            int x; cin >> x;
            sel[i].push_back(x);
            fre[x]++;
        }
    }
    
    int mx = 0;
    for (auto i = 1; i <= N; i++) {
        if (fre[i] > fre[mx])
            mx = i;
    }

    vector<int> good(M, -1), ans(M);
    int includeOther = 0;
    for (auto i = 0; i < M; i++) {
        bool hasMx = false;
        for (auto x : sel[i]) 
            hasMx |= x == mx;

        for (auto x : sel[i]) {
            if (x != mx) {
                good[i] = x;
                ans[i] = x;
                break;
            }
        }
        includeOther += good[i] != -1;

        if (hasMx)
            ans[i] = mx;
    }

    if (includeOther >= M/2) {
        cout << "YES\n";
        int lim = (M+1)/2, cfre = fre[mx];

        // printf("remgood=%d\n", remGood);
        for (auto i = 0; i < M; i++) {
            if (good[i] != -1 && ans[i] == mx && cfre > lim) {
                cout << good[i] << ' ';
                cfre--;
            }
            else
                cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        // Input
        
        solve();

        // Reset
    }
}