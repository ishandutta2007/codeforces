#include <iostream>
#include <deque>

using namespace std;

typedef long long ll;

int n, m, a, b;
int h[3333][3333];
int u[3333][3333];

int main() {
    cin >> n >> m >> a >> b;
    ll g, x, y, z;
    cin >> g >> x >> y >> z;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            h[i][j] = g;
            g = (g*x+y)%z;
        }
    }
    for (int i = 0; i < n; i++) {
        deque<pair<int,int>> d;
        for (int j = 0; j < m; j++) {
            while (d.size() && d.back().first >= h[i][j]) d.pop_back();
            d.push_back({h[i][j],j});
            if (j-d.front().second >= b) d.pop_front();
            u[i][j] = d.front().first;
        }
    }
    ll s = 0;
    for (int j = b-1; j < m; j++) {
        deque<pair<int,int>> d;
        for (int i = 0; i < n; i++) {
            while (d.size() && d.back().first >= u[i][j]) d.pop_back();
            d.push_back({u[i][j],i});
            if (i-d.front().second >= a) d.pop_front();
            if (i >= a-1) s += d.front().first;
        }
    }
    cout << s << "\n";
}