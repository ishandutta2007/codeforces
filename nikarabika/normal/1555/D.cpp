#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define L first
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define R second
#define smin(x, y) (x) = min((x), (y))
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    char arr[] = {'a', 'b', 'c'};
    int n, q;
    string s;
    cin >> n >> q;
    cin >> s;
    int sum[6][n + 1] = {0};
    for (int i = 0; i < 6; i++) {
        sum[i][0] = 0;
        for (int j = 0; j < n; j++)
            sum[i][j + 1] = sum[i][j] + (s[j] != arr[j % 3]);
        next_permutation(arr, arr + 3);
    }
    while (q--) {
        int ans = 1e6;
        int fi, se;
        cin >> fi >> se;
        fi--;
        for (int i = 0; i < 6; i++)
            smin(ans, sum[i][se] - sum[i][fi]);
        cout << ans << '\n';
    }
    return 0;
}