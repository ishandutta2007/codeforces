#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e3 + 1;

int w, b, total;

double dp[N][N];

double recurse(int i, int j) {
    if (i == 0 or i + j == 0)
        return 0;

    if (j == 0) {
        if ((total - i - j) % 3 == 0)
            return 1;
        else if ((total - i - j) % 3 == 1)
            return 0;
        else {
            if (i == 1) return 0;
            else return 1;
        }
    }

    if (dp[i][j] != 2)
        return dp[i][j];

    if ((total - i - j) % 3 == 0)
        return dp[i][j] = (double)i / (i + j) + ((double)j / (j + i)) * recurse(i, j - 1); //0.25 + 0.75 * 0.66

    else if ((total - i - j) % 3 == 1)
        return dp[i][j] = ((double)j / (j + i)) * recurse(i, j - 1);

    return dp[i][j] = ((double)i / (i + j)) * recurse(i - 1, j) + ((double)j / (j + i)) * recurse(i, j - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> w >> b;
    total = w + b;

    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) dp[i][j] = 2;

    cout << fixed << setprecision(10);
    cout << recurse(w, b);

    return 0;
}