#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld long double
mt19937 Rand(0);


const int inf = 1e9 + 7;
const int max_n = 42;

int n, A, B;
string s;
int dp[max_n][max_n][max_n][max_n];

int binpow(int a, int b, int mod) {
    int r = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1) r = r * a % mod;
    return r;
}

void run() {
    vector<int> poA(50), poB(50);
    poA[0] = poB[0] = 1;
    cin >> n >> A >> B >> s;
    for (int i = 1; i < 50; ++i)
        poA[i] = 10 * poA[i - 1] % A, poB[i] = 10 * poB[i - 1] % B;

    for (int i = 0; i < max_n; ++i) {
        for (int j = 0; j < max_n; ++j) {
            for (int q = 0; q < max_n; ++q)
                fill(dp[i][j][q], dp[i][j][q] + max_n, 0);
        }
    }
    dp[n][0][0][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int r = 0; r <= n; ++r) {
            for (int ma = 0; ma < A; ++ma) {
                for (int mb = 0; mb < B; ++mb) {
                    if (!dp[i + 1][r][ma][mb]) continue;
                    int q1 = (s[i] - '0') * poA[r] % A;
                    int q2 = (s[i] - '0') * poB[n - i - 1 - r] % B;
                    dp[i][r + 1][(ma + q1) % A][mb] = 1;
                    dp[i][r][ma][(mb + q2) % B] = 2;
                }
            }
        }
    }
    int id1 = 0, id2 = -inf, id3 = 0, id4 = 0;
    for (int i = 1; i < n; ++i) {
        if (dp[0][i][0][0] && abs(n - 2 * id2) >= abs(n - 2 * i))
            id2 = i;
    }

    if (id2 == -inf) {
        cout << -1 << endl;
        return;
    }

    while (id1 < n) {
        //cout << id1 << " " << id2 << " " << id3 << " " << id4 << endl;
        if (dp[id1][id2][id3][id4] == 1) {
            int q1 = (s[id1] - '0') * poA[id2 - 1] % A;
            --id2;
            id3 = (id3 - q1 + A) % A;
            cout << "R";
        }
        else {
            int q2 = (s[id1] - '0') * poB[n - id1 - 1 - id2] % B;
            id4 = (id4 - q2 + B) % B;
            cout << "B";
        }
        ++id1;
    }
    cout << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        run();
    }
}