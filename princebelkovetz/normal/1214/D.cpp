#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(7);
    int n, m; cin >> n >> m;
    vector <string> a(n);
    for (auto& x : a) cin >> x;
    vector <vector <pair <bool, bool>>> dist(n, vector <pair <bool, bool>>(m));
    queue <pair <int, int>> q; q.push({ 0, 0 });
    dist[0][0].first = true;
    while (q.size()) {
        pair <int, int> v = q.front(); q.pop();
        if (v.first < n - 1 and !dist[v.first + 1][v.second].first and a[v.first + 1][v.second] != '#') {
            q.push({ v.first + 1, v.second });
            dist[v.first + 1][v.second].first = true;
        }
        if (v.second < m - 1 and !dist[v.first][v.second + 1].first and a[v.first][v.second + 1] != '#'){
            q.push({ v.first, v.second + 1 });
            dist[v.first][v.second + 1].first = true;
        }
    }
    queue <pair <int, int>> q2; q2.push({ n - 1, m - 1 });
    dist[n - 1][m - 1].second = true;
    while (q2.size()) {
        pair <int, int> v = q2.front(); q2.pop();
        if (v.first > 0 and !dist[v.first - 1][v.second].second and a[v.first - 1][v.second] != '#'){
            q2.push({ v.first - 1, v.second });
            dist[v.first - 1][v.second].second = true;
        }
        
        if (v.second > 0 and !dist[v.first][v.second - 1].second and a[v.first][v.second - 1] != '#') {
            q2.push({ v.first, v.second - 1 });
            dist[v.first][v.second - 1].second = true;
        }
    }
    map <int, int> cnt;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) 
            if (i + j != 0 and i + j != n + m - 2 and dist[i][j].first & dist[i][j].second) cnt[i + j]++;
    if (!dist[n - 1][m - 1].first) cout << "0\n";
    else {
        bool flag = true;
        for (auto x : cnt) if (x.second < 2) 
            flag = false;
        
        if (flag) cout << "2\n";
        else cout << "1\n";
    }

}