#include <bits/stdc++.h>

using namespace std;

vector < pair < int, int > > answer;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("1.inp" ,"r")) freopen("1.inp", "r", stdin);

    int n, m; cin >> n >> m;
    vector < vector < int > > a(n, vector < int > (m, 0));

    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        for(int j = 0; j < m; ++j) {
            if(s[j] == 'X') a[i][j] = 1;
        }
    }

    auto c = a;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(i > 0) a[i][j] += a[i - 1][j];
            if(j > 0) a[i][j] += a[i][j - 1];
            if(i > 0 && j > 0) a[i][j] -= a[i - 1][j - 1];
        }
    }


    int low = 0, high = n * m, ans = 0;
    while(low <= high) {
        int mid = (low + high) >> 1;

        vector < pair < int, int > > trees;
        vector < vector < int > > b(n, vector < int > (m, 0));

        for(int i = mid; i < n - mid; ++i) {
            for(int j = mid; j < m - mid; ++j) {
                int lx = max(0, i - mid), ly = max(0, j - mid);
                int rx = min(n - 1, i + mid), ry = min(m - 1, j + mid);
                int calc = a[rx][ry];
                if(lx > 0) calc -= a[lx - 1][ry];
                if(ly > 0) calc -= a[rx][ly - 1];
                if(lx > 0 && ly > 0) calc += a[lx - 1][ly - 1];
                if(calc == (rx - lx + 1) * (ry - ly + 1)) {
                    trees.emplace_back(i, j);
                    ++b[lx][ly];
                    if(rx < n - 1) --b[rx + 1][ly];
                    if(ry < m - 1) --b[lx][ry + 1];
                    if(rx < n - 1 && ry < m - 1) ++b[rx + 1][ry + 1];
                }
            }
        }


        bool flag = true;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(i > 0) b[i][j] += b[i - 1][j];
                if(j > 0) b[i][j] += b[i][j - 1];
                if(i > 0 && j > 0) b[i][j] -= b[i - 1][j - 1];
                if((!!b[i][j]) != c[i][j]) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) {
            ans = mid;
            low = mid + 1;
            answer = trees;
        }
        else {
            high = mid - 1;
        }
    }

    cout << ans << "\n";
    vector < string > risan (n, string(m, '.'));
    for(auto p : answer) risan[p.first][p.second] = 'X';
    for(auto s : risan) cout << s << "\n";

    return 0;
}