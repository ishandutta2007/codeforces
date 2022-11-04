#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

vector <int> g[MAXN + 1];
int cnt = 0;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, s;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> s;
    for(i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(i = 1; i <= n; i++) {
        if(g[i].size() == 1) {
            cnt++;
        }
    }
    cout << fixed << setprecision(20) << 2.0 * s / cnt;
    //cin.close();
    //cout.close();
    return 0;
}