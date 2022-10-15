#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v[202020];
int d[202020];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n-1; i++) {
        v[i].push_back(i+1);
        v[i+1].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v[i].push_back(x);
    }
    vector<int> q;
    q.push_back(1);
    d[1] = 0;
    for (int i = 2; i <= n; i++) d[i] = 999999999;
    for (int i = 0; i < q.size(); i++) {
        int s = q[i];
        int e = d[q[i]];
        for (int j = 0; j < v[s].size(); j++) {
            int u = v[s][j];
            if (e+1 < d[u]) {
                d[u] = e+1;
                q.push_back(u);
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << d[i] << " ";
    cout << "\n";
}