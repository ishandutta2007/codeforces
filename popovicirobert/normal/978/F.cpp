#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

vector <int> g[MAXN + 1];

pair <int, int> r[MAXN + 1];
int v[MAXN + 1];
int sol[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k, x, y;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(i = 1; i <= n; i++) {
        cin >> r[i].first;
        r[i].second = i;
        v[i] = r[i].first;
    }
    sort(r + 1, r + n + 1);
    int pos = 1;
    for(i = 1; i <= n; i++) {
        while(r[pos].first < r[i].first)
            pos++;
        sol[r[i].second] = pos - 1;
    }
    for(i = 1; i <= k; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(i = 1; i <= n; i++) {
        for(auto it : g[i]) {
            if(v[i] > v[it])
                sol[i]--;
        }
        cout << sol[i] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}