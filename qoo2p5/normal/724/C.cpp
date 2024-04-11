#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const ll INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld EPS = 1e-9;

const int N = 3e5 + 123;
const int C = 1e5 + 123;

int n, m, k;
vector<pair<pair<int, int>, int>> p1[N]; // x + y 
vector<pair<pair<int, int>, int>> p2[N]; // x - y + C
bool vis[N][4];
ll ans[N];

int run() {
    cin >> n >> m >> k;
    fill(ans, ans + k, LINF);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        p1[x + y].push_back(make_pair(make_pair(x, y), i));
        p2[x - y + C].push_back(make_pair(make_pair(x, y), i));
    }
    
    int cur_x = 0;
    int cur_y = 0;
    ll cur_t = 0;
    int dx = 1;
    int dy = 1;
    
    map<pair<int, int>, int> tt;
    tt[make_pair(1, 1)] = 0;
    tt[make_pair(1, -1)] = 1;
    tt[make_pair(-1, -1)] = 2;
    tt[make_pair(-1, 1)] = 3;
    
    while (1) {
        int cur_type = tt[make_pair(dx, dy)];
        int cur_coef;
        if (cur_type == 0 || cur_type == 2) { // x - y = coef
            cur_coef = cur_x - cur_y;
        } else { // x + y = coef
            cur_coef = cur_x + cur_y;
        }
        
        if (vis[cur_coef + C][cur_type]) {
            break;
        }
        
        vis[cur_coef + C][cur_type] = true;
        
        if (cur_type == 0 || cur_type == 2) {
            for (auto &el : p2[cur_coef + C]) {
                ans[el.second] = min(ans[el.second], cur_t + abs(el.first.first - cur_x));
            }
        } else {
            for (auto &el : p1[cur_coef]) {
                ans[el.second] = min(ans[el.second], cur_t + abs(el.first.first - cur_x));
            }
        }
        
        if (cur_type == 0) {
            if (m - cur_y == n - cur_x) {
                break;
            } else if (m - cur_y < n - cur_x) {
                int dt = (m - cur_y);
                cur_t += dt;
                cur_x += dx * dt;
                cur_y += dy * dt;
                dy = -dy;
            } else {
                int dt = (n - cur_x);
                cur_t += dt;
                cur_x += dx * dt;
                cur_y += dy * dt;
                dx = -dx;
            }
        } else if (cur_type == 1) {
            if (n - cur_x == cur_y) {
                break;
            } else if (cur_y < n - cur_x) {
                int dt = cur_y;
                cur_t += dt;
                cur_x += dx * dt;
                cur_y += dy * dt;
                dy = -dy;
            } else {
                int dt = (n - cur_x);
                cur_t += dt;
                cur_x += dx * dt;
                cur_y += dy * dt;
                dx = -dx;
            }
        } else if (cur_type == 2) {
            if (cur_y == cur_x) {
                break;
            } else if (cur_y < cur_x) {
                int dt = cur_y;
                cur_t += dt;
                cur_x += dx * dt;
                cur_y += dy * dt;
                dy = -dy;
            } else {
                int dt = cur_x;
                cur_t += dt;
                cur_x += dx * dt;
                cur_y += dy * dt;
                dx = -dx;
            }
        } else if (cur_type == 3) {
            if (cur_x == m - cur_y) {
                break;
            } else if (m - cur_y < cur_x) {
                int dt = m - cur_y;
                cur_t += dt;
                cur_x += dx * dt;
                cur_y += dy * dt;
                dy = -dy;
            } else {
                int dt = cur_x;
                cur_t += dt;
                cur_x += dx * dt;
                cur_y += dy * dt;
                dx = -dx;
            }
        }
    }
    
    for (int i = 0; i < k; i++) {
        cout << (ans[i] == LINF ? -1 : ans[i]) << "\n";
    }
    
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    return run();
}