#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 50;
const int INF = (int) 1e9;

int dp[MAXN + 1];

int v[MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    int sum = 0;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    for(i = n; i >= 1; i--) {
        sum += v[i];
        dp[i] = max(sum - dp[i + 1], dp[i + 1]);
    }
    cout << sum - dp[1] << " " << dp[1];
    //cin.close();
    //cout.close();
    return 0;
}