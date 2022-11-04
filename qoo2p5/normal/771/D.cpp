#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define sz(x) (int) (x).size()
const int INF = (int) 1e9 + 123;

void run();

int main() {
#ifndef LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    run();
    return 0;
}

const int N = 80;

int n;
string s;
int a[N];
int dp[N][N][N][2];
vector<int> p[3];

int calc(int v, int k, int x, int pos) {
    int res = 0;
    
    int cnt[3] = {0, 0, 0};
    for (int i = 0; i < pos; i++) {
        cnt[a[i]]++;
    }
    
    res += max(cnt[0], v);
    res += max(cnt[1], k);
    res += max(cnt[2], x);
    
    return abs(res - (v + k + x));
}

void run() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'V') {
            a[i] = 0;
        } else if (s[i] == 'K') {
            a[i] = 1;
        } else {
            a[i] = 2;
        }
        p[a[i]].push_back(i);
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int t = 0; t < N; t++) {
                for (int k = 0; k < 2; k++) {
                    dp[i][j][t][k] = INF;
                }
            }
        }
    }
    
    dp[0][0][0][0] = 0;
    
    for (int v = 0; v <= sz(p[0]); v++) {
        for (int k = 0; k <= sz(p[1]); k++) {
            for (int x = 0; x <= sz(p[2]); x++) {
                for (int t = 0; t < 2; t++) {
                    if (v != sz(p[0])) {
                        dp[v + 1][k][x][1] = min(dp[v + 1][k][x][1], dp[v][k][x][t] + calc(v, k, x, p[0][v]));
                    }
                    
                    if (!t && k != sz(p[1])) {
                        dp[v][k + 1][x][0] = min(dp[v][k + 1][x][0], dp[v][k][x][t] + calc(v, k, x, p[1][k]));
                    }
                    
                    if (x != sz(p[2])) {
                        dp[v][k][x + 1][0] = min(dp[v][k][x + 1][0], dp[v][k][x][t] + calc(v, k, x, p[2][x]));
                    }
                }
            }
        }
    }
    
    cout << min(dp[sz(p[0])][sz(p[1])][sz(p[2])][0], dp[sz(p[0])][sz(p[1])][sz(p[2])][1]);
}