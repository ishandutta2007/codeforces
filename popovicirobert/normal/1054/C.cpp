#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int INF = 1e9;
const int MAXN = 1e3;

int l[MAXN + 1], r[MAXN + 1];
int sol[MAXN + 1];
bool vis[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> l[i];
    }
    for(i = 1; i <= n; i++) {
        cin >> r[i];
        if(l[i] + r[i] >= n) {
            cout << "NO";
            return 0;
        }
    }
    int cur = n, cnt = 0;
    for(int t = 1; t <= n; t++) {
        memset(vis, 0, sizeof(vis));
        int aux = cnt;
        for(i = 1; i <= n; i++) {
            if(l[i] + r[i] == 0) {
                vis[i] = 1;
                cnt++;
            }
        }
        if(cnt == aux) {
            cout << "NO";
            return 0;
        }
        for(i = 1; i <= n; i++) {
            if(vis[i] == 1) {
                sol[i] = cur;
                for(j = i + 1; j <= n; j++) {
                    l[j]--;
                    if(l[j] < 0 && vis[j] == 0) {
                        cout << "NO";
                        return 0;
                    }
                }
                for(j = 1; j < i; j++) {
                    r[j]--;
                    if(r[j] < 0 && vis[j] == 0) {
                        cout << "NO";
                        return 0;
                    }
                }
                l[i] = r[i] = INF;
            }
        }
        cur--;
        if(cnt == n) {
            break;
        }
    }
    cout << "YES" << "\n";
    for(i = 1; i <= n; i++) {
        cout << sol[i] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}