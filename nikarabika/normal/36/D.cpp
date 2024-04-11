//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int q, k;
    cin >> q >> k;
    k++;
    while (q--) {
        int n, m;
        cin >> n >> m;
        if (k == 2) {
            cout << ((n & 1) and (m & 1) ? '-' : '+') << endl;
            continue;
        }
        if (n > m)
            swap(n, m);
        if (n % k == 0)
            cout << '+' << endl;
        else if ((n & 1) xor (m & 1) xor ((n / k) & 1))
            cout << '+' << endl;
        else
            cout << '-' << endl;
    }
//    Find Pattern :D
//
//    int k, z;
//    cin >> k >> z;
//    int n = k * z;
//    bool dp[n][n];
//    memset(dp, 0, sizeof dp);
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < n; j++) {
//            if (i and not dp[i - 1][j])
//                dp[i][j] = 1;
//            if (j and not dp[i][j - 1])
//                dp[i][j] = 1;
//            if (i >= k and j >= k and not dp[i - k][j - k])
//                dp[i][j] = 1;
//        }
//    for (int i = 0; i < n; i++, cout << endl)
//        for (int j = 0; j < n; j++)
//            cout << (dp[i][j] ? '#' : ' ') << ' ';
	return 0;
}