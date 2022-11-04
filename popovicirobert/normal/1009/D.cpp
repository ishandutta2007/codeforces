#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = (int) 1e5;

vector <int> g[MAXN + 1];

inline int gcd(int a, int b) {
    int r;
    while(b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    if(m < n - 1) {
        cout << "Impossible";
        return 0;
    }
    for(i = 1; i < n; i++) {
        for(j = i + 1; j <= n; j++) {
            if(gcd(i, j) == 1) {
                g[i].push_back(j);
                m--;
                if(m == 0) {
                    cout << "Possible" << "\n";
                    for(int nod = 1; nod <= n; nod++) {
                        for(auto it : g[nod]) {
                            cout << nod << " " << it << "\n";
                        }
                    }
                    return 0;
                }
            }
        }
    }
    cout << "Impossible";
    //cin.close();
    //cout.close();
    return 0;
}