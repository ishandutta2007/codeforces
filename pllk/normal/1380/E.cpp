#include <iostream>
#include <vector>

using namespace std;

int n, m;
int t[202020];
int qa[202020];
int qb[202020];

int wa[202020];
int wb[202020];
vector<int> vv[202020];

int ss[404040];
int tt[404040];

int kk[202020];

int id(int x) {
    while (x != tt[x]) x = tt[x];
    return x;
}

void merge(int a, int b) {
    a = id(a);
    b = id(b);
    if (a == b) return;
    if (ss[a] < ss[b]) swap(a,b);
    ss[a] += ss[b];
    tt[b] = a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= m-1; i++) cin >> qa[i] >> qb[i];
    for (int i = 1; i <= n; i++) {
        wa[i] = 0;
        wb[i] = m;
    }
    for (int h = 0; h < 20; h++) {
        for (int i = 0; i <= m+1; i++) vv[i].clear();
        for (int i = 1; i <= n; i++) {
            vv[(wa[i]+wb[i])/2].push_back(i);
        }
        for (int i = 1; i <= 2*n; i++) ss[i] = 0;
        for (int i = 1; i <= n; i++) {
            tt[i] = n+t[i];
            ss[n+t[i]]++;
            tt[n+i] = n+i;
            ss[n+i]++;
        }
        for (int i = 0; i <= m-1; i++) {
            if (i != 0) merge(n+qa[i],n+qb[i]);
            for (auto x : vv[i]) {
                if (x == n || id(x) == id(x+1)) {
                    wb[x] = i;
                } else {
                    wa[x] = i+1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) kk[wa[i]]++;
    int r = 0;
    for (int i = 0; i < m; i++) {
        r += kk[i];
        cout << n-r << "\n";
    }
}