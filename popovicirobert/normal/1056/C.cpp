#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 1000;

int arr[2 * MAXN + 1];
int x[MAXN + 1], y[MAXN + 1];
bool vis[2 * MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m;
    //ios::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(i = 1; i <= 2 * n; i++) {
        cin >> arr[i];
    }
    for(i = 1; i <= m; i++) {
        cin >> x[i] >> y[i];
        if(arr[x[i]] < arr[y[i]]) {
            swap(x[i], y[i]);
        }
    }
    int t;
    cin >> t;
    int id;
    if(t == 1) {
        for(i = 1; i <= n; i++) {
            bool ok = 0;
            for(j = 1; j <= m; j++) {
                if(vis[x[j]] == 0) {
                    vis[x[j]] = 1;
                    cout << x[j] << "\n";
                    ok = 1;
                    break;
                }
            }
            if(!ok) {
                int mx = 0;
                for(j = 1; j <= 2 * n; j++) {
                    if(vis[j] == 0 && arr[j] > mx) {
                        mx = arr[j];
                        id = j;
                    }
                }
                cout << id << "\n";
                vis[id] = 1;
            }
            cin >> id;
            vis[id] = 1;
        }
    }
    else {
        for(i = 1; i <= n; i++) {
            cin >> id;
            bool ok = 0;
            vis[id] = 1;
            for(j = 1; j <= m; j++) {
                if(x[j] == id) {
                    if(vis[y[j]] == 0) {
                        cout << y[j] << "\n";
                        ok = 1;
                        vis[y[j]] = 1;
                        break;
                    }
                }
                else if(y[j] == id) {
                    if(vis[x[j]] == 0) {
                        cout << x[j] << "\n";
                        ok = 1;
                        vis[x[j]] = 1;
                        break;
                    }
                }
            }
            if(!ok) {
                for(j = 1; j <= m; j++) {
                    if(vis[x[j]] == 0) {
                        cout << x[j] << "\n";
                        vis[x[j]] = 1;
                        ok = 1;
                        break;
                    }
                }
                if(!ok) {
                    int mx = 0;
                    for(j = 1; j <= 2 * n; j++) {
                        if(vis[j] == 0 && mx < arr[j]) {
                            mx = arr[j];
                            id = j;
                        }
                    }
                    cout << id << "\n";
                    vis[id] = 1;
                }
            }
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}