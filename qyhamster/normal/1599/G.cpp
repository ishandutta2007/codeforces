#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 10;
const int inf = 1e9;
const int MOD = 1e9 + 7;
int x[maxn], y[maxn];
pair<int,int> p[maxn];
bool col(int u, int v, int w) {
    return ((x[v]-x[u])*(y[w]-y[u]) == (x[w]-x[u])*(y[v]-y[u]));
}
double dis(int u, int v) {
    return sqrt((p[u].first-p[v].first)*(p[u].first-p[v].first) + (p[u].second-p[v].second)*(p[u].second-p[v].second));
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k; k--;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    int X = x[k], Y = y[k];
    if(n > 3) {
        int cnt = 0;
        for(int i = 2; i < n; i++) {
            if(col(0,1,i)) cnt++;
        }
        if(cnt < n-3) {
            swap(x[0], x[2]);
            swap(x[1], x[3]);
            swap(y[0], y[2]);
            swap(y[1], y[3]);
        }
    }
    int key = 0;
    for(int i = 2; i < n; i++) {
        if(!col(0,1,i)) {
            key = i;
            break;
        }
    }
    swap(x[0], x[key]);
    swap(y[0], y[key]);
    for(int i = 0; i < n; i++) {
        p[i].first = x[i];
        p[i].second = y[i];
    }
    sort(p+1, p+n);
    vector<pair<int,int>> t;
    t.push_back(p[1]);
    for(int i = 2; i < n; i++) {
        if(p[i].first != p[i-1].first || p[i].second != p[i-1].second) {
            t.push_back(p[i]);
        }
    }
    n = t.size() + 1;
    for(int i = 1; i < n; i++) p[i] = t[i-1];
    int K = 0;
    for(int i = 1; i <= n; i++) {
        if(p[i].first == X && p[i].second == Y) K = i;
    }
    if(K == 0) {
        cout << setprecision(10) << fixed << min(dis(0, 1), dis(0, n-1)) + dis(1, n-1) << endl;
        return 0;
    }
    double ans = dis(1, n-1) + min(dis(1, K) + dis(n-1, 0), dis(K, n-1) + dis(1, 0));
    for(int i = 1; i < K; i++) {
        ans = min(ans, dis(1,i) + dis(i,0) + dis(i+1, n-1) + min(dis(0, i+1) + dis(K, n-1), dis(0, n-1) + dis(K, i+1)));
    }
    for(int i = n-1; i > K; i--) {
        ans = min(ans, dis(n-1,i) + dis(i,0) + dis(i-1, 1) + min(dis(0, i-1) + dis(K, 1), dis(0, 1) + dis(K, i-1)));
    }
    cout << setprecision(10) << fixed << ans << endl;
    return 0;
}