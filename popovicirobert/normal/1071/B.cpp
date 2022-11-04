#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 2000;
const int B = 41;
const int LOG = 13;

char str[MAXN + 1][MAXN + 1];
int cnt[MAXN + 1][MAXN + 1];
bool vis[MAXN + 1][MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(i = 1; i <= n; i++) {
        cin >> str[i] + 1;
    }
    for(i = 0; i <= n; i++) {
        cnt[0][i] = cnt[i][0] = 2 * n;
    }
    cnt[1][1] = (str[1][1] != 'a');
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if(i == 1 && j == 1) {
                continue;
            }
            cnt[i][j] = min(cnt[i - 1][j], cnt[i][j - 1]) + (str[i][j] != 'a');
        }
    }
    if(cnt[n][n] <= k) {
        for(i = 1; i < 2 * n; i++) {
            cout << 'a';
        }
        return 0;
    }
    vector < pair <int, int> > Q;
    int mx = 0;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if(cnt[i][j] == k) {
                mx = max(mx, i + j);
            }
        }
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if(cnt[i][j] == k && mx == i + j) {
                if(j < n && !vis[i][j + 1]) {
                    Q.push_back({i, j + 1});
                    vis[i][j + 1] = 1;
                }
                if(i < n && !vis[i + 1][j]) {
                    Q.push_back({i + 1, j});
                    vis[i + 1][j] = 1;
                }
            }
        }
    }
    for(i = 1; i < mx; i++) {
        cout << 'a';
    }
    if(Q.empty()) {
        Q.push_back({1, 1});
        vis[1][1] = 1;
    }
    while(!Q.empty()) {
        char mn = 'z';
        for(auto it : Q) {
            mn = min(mn, str[it.first][it.second]);
        }
        cout << mn;
        vector < pair <int, int> > aux;
        for(auto it : Q) {
            if(str[it.first][it.second] == mn) {
                if(it.first < n && vis[it.first + 1][it.second] == 0) {
                    aux.push_back({it.first + 1, it.second});
                    vis[it.first + 1][it.second] = 1;
                }
                if(it.second < n && vis[it.first][it.second + 1] == 0) {
                    aux.push_back({it.first, it.second + 1});
                    vis[it.first][it.second + 1] = 1;
                }
            }
        }
        Q.clear();
        Q = aux;
    }
    //cin.close();
    //cout.close();
    return 0;
}