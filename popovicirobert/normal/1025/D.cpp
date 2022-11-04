#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 700;

int arr[MAXN + 1];

vector <int> id[MAXN + 1];
vector < vector <char> > dp[MAXN + 1];
bool aux[MAXN + 1][MAXN + 1][2];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if(i != j && __gcd(arr[i], arr[j]) > 1) {
                id[i].push_back(j);
            }
        }
    }
    for(i = 1; i <= n; i++) {
        dp[i].resize(n - i + 2);
        for(j = 1; j <= n - i + 1; j++) {
            dp[i][j].resize(j + 1);
        }
    }
    for(i = 1; i < n; i++) {
        dp[i][2][1] = dp[i][2][2] = (__gcd(arr[i], arr[i + 1]) > 1);
        aux[i + 1][i + 1][0] = aux[i][i][1] = dp[i][2][1];
    }
    for(int len = 3; len <= n; len++) {
        for(i = 1; i + len - 1 <= n; i++) {
            int l = i, r = i + len - 1;
            for(int nod = l + 1; nod < r; nod++) {
                dp[l][r - l + 1][nod - l + 1] = (aux[l][nod - 1][1] & aux[nod + 1][r][0]);
            }
            for(auto it : id[l]) {
                if(l + 1 <= it && it <= r) {
                    aux[l + 1][r][0] |= dp[l + 1][r - l][it - l];
                }
            }
            for(auto it : id[r]) {
                if(l <= it && it <= r - 1) {
                    aux[l][r - 1][1] |= dp[l][r - l][it - l + 1];
                }
            }
            dp[l][r - l + 1][1] = aux[l + 1][r][0];
            dp[l][r - l + 1][r - l + 1] = aux[l][r - 1][1];
        }
    }
    bool ans = 0;
    for(i = 1; i <= n && ans == 0; i++) {
        ans |= dp[1][n][i];
    }
    if(ans) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    //cin.close();
    //cout.close();
    return 0;
}