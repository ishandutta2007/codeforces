#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int n, m;
vector<int> v[3333];
vector<pair<int,int>> k;
int x[3333][3333];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            int u = v[i][j];
            for (int k = 0; k < v[u].size(); k++) {
                int z = v[u][k];
                x[i][z]++;
            }
        }
    }
    ll c = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            c += (ll)x[i][j]*(x[i][j]-1)/2;
        }
    }
    cout << c << "\n";
}