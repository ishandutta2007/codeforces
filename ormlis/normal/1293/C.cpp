 
 
#include <bits/stdc++.h>
 
#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
 
using namespace std;
 
typedef long long ll;
 
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 100001;
ll md = 998244353;
vector<vector<int>> s(2, vector<int> (maxN, 0)), bad(2, vector<int> (maxN, 0));
int n, q;
int answer = 0;

void check(int r, int c) {
    int ans = 0;
    if (s[r][c] == 1 && (s[r^1][c] == 1 || (c < n - 1 && s[r^1][c + 1] == 1) || (c > 0 && s[r^1][c - 1]))) ans = 1;
    if (bad[r][c] != ans) {
        bad[r][c] = ans;
        if (ans) answer++;
        else answer--;
    }
}

void check2(int r, int c) {
    for(int c1 = max(c - 1, 0); c1 <= min(c + 1, n - 1); ++c1) {
        check(1, c1);
        check(0, c1);
    }
}  
 
void solve() {
    cin >> n >> q;
    range(i, q) {
        int r, c; cin >> r >> c;
        r--; c--;
        s[r][c] = 1^s[r][c];
        check2(r, c);
        if (answer) cout << "No\n";
        else cout << "Yes\n";
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}