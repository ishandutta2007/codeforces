#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 100;
const int MAXT = 2000;

struct Data {
    int t, d, p;
    int pos;
    bool operator <(const Data &other) const {
        return d < other.d;
    }
}v[MAXN + 1];

int dp[MAXN + 1][MAXT + 1];

vector <int> sol;

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i].t >> v[i].d >> v[i].p;
        v[i].pos = i;
    }
    sort(v + 1, v + n + 1);
    for(i = 1; i <= n; i++) {
        for(j = 0; j <= MAXT; j++)
            dp[i][j] = dp[i - 1][j];
        for(j = v[i].t; j < v[i].d; j++)
            if(dp[i][j] < dp[i - 1][j - v[i].t] + v[i].p)
                dp[i][j] = dp[i - 1][j - v[i].t] + v[i].p;
    }
    int ans = 0;
    int pos;
    for(i = 0; i <= MAXT; i++)
        if(ans < dp[n][i]) {
            ans = dp[n][i];
            pos = i;
        }
    cout << ans << endl;
    i = n;
    j = pos;
    while(i >= 1 && j >= 0) {
        if(j - v[i].t >= 0 && dp[i][j] == dp[i - 1][j - v[i].t] + v[i].p) {
            sol.push_back(v[i].pos);
            j -= v[i].t;
            i--;
        }
        else
            i--;
    }
    cout << sol.size() << endl;
    for(i = (int) sol.size() - 1; i >= 0; i--)
        cout << sol[i] << " ";
    //cin.close();
    //cout.close();
    return 0;
}