#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const ll INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld EPS = 1e-9;

const int N = 21;

int n, m;
int a[N][N];
int p[N];
bool ok[N][N][N][N][N];

int calc() {
    int res = 0;
    for (int i = 0; i < m; i++) {
        res += p[i] != (i + 1);
    }
    
    return res;
}

void yes() {
    cout << "YES\n";
    exit(0);
}

int run() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    bool only_first = true;
    
    for (int i = 0; i < n; i++) {
        copy(a[i], a[i] + m, p);
        only_first &= calc() <= 2;
    }
    
    if (only_first) {
        yes();
    }
    
    for (int i = 0; i < n; i++) {
        for (int p1 = 0; p1 < m; p1++) {
            for (int p2 = 0; p2 < m; p2++) {
                for (int q1 = 0; q1 < m; q1++) {
                    for (int q2 = 0; q2 < m; q2++) {
                        copy(a[i], a[i] + m, p);
                        swap(p[p1], p[p2]);
                        swap(p[q1], p[q2]);
                        
                        ok[i][p1][p2][q1][q2] = calc() == 0;
                    }
                }
            }
        }
    }
    
    for (int u = 0; u < m; u++) {
        for (int v = u + 1; v < m; v++) {
            bool good = true;
            for (int i = 0; i < n; i++) {
                bool cur = false;
                for (int p1 = 0; p1 < m; p1++) {
                    for (int p2 = 0; p2 < m; p2++) {
                        cur |= ok[i][u][v][p1][p2];
                        cur |= ok[i][p1][p2][u][v];
                    }
                }
                
                good &= cur;
            }
            
            if (good) yes();
        }
    }
    
    cout << "NO\n";
    
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    return run();
}