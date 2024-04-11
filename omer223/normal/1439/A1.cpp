#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back

#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pii inst;


const int sz = 5e2;
bool a[sz][sz];
int n, m;

void solve() {
    cin >> n >> m;
    foru(i, 0, n) {
        string s;
        cin >> s;
        foru(j, 0, m)a[i][j] = (s[j] == '1');
    }
    vector<vector<pii>> v;
    if (m & 1) {
        for (int i = 0; i < n; i += 2) {
            if (i == n - 1)i--;
            int tot = 3;
            vector<inst> tmp;
            if (a[i][m - 1]) {
                tot--;
                tmp.pb({i, m - 1});
                a[i][m - 1] = 0;
            }
            if (a[i + 1][m-1]) {
                tot--;
                tmp.pb({i + 1, m - 1});
                a[i + 1][m-1] = 0;
            }
            if (tmp.empty())continue;
            foru(j, 0, tot) {
                tmp.pb({i + j, m - 2});
                a[i + j][m - 2] = !a[i + j][m - 2];
            }
            v.pb(tmp);
        }
        m--;
    }
    while (n > 2) {
        for (int i = 0; i < m; i += 2) {
            int tot = 3;
            vector<inst> tmp;
            if (a[n - 1][i]) {
                tot--;
                tmp.pb({n - 1, i});
                a[n - 1][i] = 0;
            }
            if (a[n - 1][i + 1]) {
                tot--;
                tmp.pb({n - 1, i + 1});
                a[n - 1][i + 1] = 0;
            }
            if (tmp.empty())continue;
            foru(j, 0, tot) {
                tmp.pb({n - 2, i + j});
                a[n - 2][i + j] = !a[n - 2][i + j];
            }
            v.pb(tmp);
        }
        n--;
    }
    while (m > 2) {
        for (int i = 0; i < n; i += 2) {
            int tot = 3;
            vector<inst> tmp;
            if (a[i][m - 1]) {
                tot--;
                tmp.pb({i, m - 1});
                a[i][m - 1] = 0;
            }
            if (a[i + 1][m-1]) {
                tot--;
                tmp.pb({i + 1, m - 1});
                a[i + 1][m-1] = 0;
            }
            if (tmp.empty())continue;
            foru(j, 0, tot) {
                tmp.pb({i + j, m - 2});
                a[i + j][m - 2] = !a[i + j][m - 2];
            }
            v.pb(tmp);
        }
        m--;
    }
    while(true){
        vector<inst> z,o;
        foru(i, 0, n) {
            foru(j, 0, m){
                if(!a[i][j])z.pb({i,j});
                else o.pb({i,j});
            }
        }
        if(o.empty())break;
        vector<inst> tmp;
        switch(o.size()){
            case 1:
                foru(i,0,2){tmp.pb(z[i]);a[z[i].first][z[i].second]=1;}
                foru(i,0,1){tmp.pb(o[i]);a[o[i].first][o[i].second]=0;}
                break;
            case 2:
                foru(i,0,2){tmp.pb(z[i]);a[z[i].first][z[i].second]=1;}
                foru(i,0,1){tmp.pb(o[i]);a[o[i].first][o[i].second]=0;}
                break;
            case 3:
                foru(i,0,0){tmp.pb(z[i]);a[z[i].first][z[i].second]=1;}
                foru(i,0,3){tmp.pb(o[i]);a[o[i].first][o[i].second]=0;}
                break;
            case 4:
                foru(i,0,0){tmp.pb(z[i]);a[z[i].first][z[i].second]=1;}
                foru(i,0,3){tmp.pb(o[i]);a[o[i].first][o[i].second]=0;}
                break;
        }
        v.pb(tmp);
    }
    cout << v.size() << '\n';
    for (auto x : v) {
        foru(i, 0, 3)cout << x[i].first + 1 << ' ' << x[i].second + 1 << ' ';
        cout << '\n';
    }
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}