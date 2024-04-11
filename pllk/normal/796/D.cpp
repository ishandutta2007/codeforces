#include <iostream>
#include <vector>

using namespace std;

int n, k, d;
int p[303030];
vector<int> v[303030];
vector<int> w[303030];

int e[303030];
vector<int> q;
vector<int> r;
int z[303030];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> d;
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        p[x] = 1;
    }
    for (int i = 1; i <= n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        w[a].push_back(i);
        v[b].push_back(a);
        w[b].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        e[i] = 999999999;
        if (p[i]) {
            e[i] = 0;
            q.push_back(i);
        }
    }
    for (int i = 0; i < q.size(); i++) {
        int s = q[i];
        for (int j = 0; j < v[s].size(); j++) {
            int f = v[s][j];
            int g = w[s][j];
            if (z[g]) continue;
            z[g] = 1;
            if (e[f] > e[s]+1) {
                e[f] = e[s]+1;
                q.push_back(f);
            } else {
                r.push_back(g);
            }
        }
    }
    cout << r.size() << "\n";
    for (int i = 0; i < r.size(); i++) cout << r[i] << " ";
    cout << "\n";
}