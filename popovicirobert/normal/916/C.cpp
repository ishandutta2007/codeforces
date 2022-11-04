#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 92

using namespace std;

const int MAXN = (int) 1e5;
const int INF = (int) 1e9;

bool ciur[2 * MAXN + 1];

vector < pair <int, int> > g[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 2; i * i <= 2 * MAXN; i++) {
        if(ciur[i] == 0)
            for(j = i * i; j <= 2 * MAXN; j += i)
                ciur[j] = 1;
    }
    int val = n;
    while(ciur[val] == 1) {
        val++;
    }
    for(i = 1; i < n - 1; i++) {
        g[i].push_back({i + 1, 1});
        m--;
    }
    g[n - 1].push_back({n, val - (n - 2)});
    m--;
    for(i = 1; i < n; i++) {
        for(j = i + 2; j <= n && m > 0; j++) {
            g[i].push_back({j, INF});
            m--;
        }
    }
    cout << val << " " << val << endl;
    for(i = 1; i <= n; i++) {
        for(auto it : g[i]) {
            cout << i << " " << it.first << " " << it.second << "\n";
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}