#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const bool debug = true;
#else
const bool debug = false;
#define cerr if (true) {} else cout
#endif

#define int long long
#define double long double

const int INF = 1000000000000000000LL;
const int mod = 1000000007;

bool tab[10000];
int v[10000];

vector<int> vp[2];
int p[2];
int pom[2];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int a, i = 1; i <= n; i++) {
        cin >> a;
        tab[a] = 1;
        v[i] = a;
    }
    
    for (int i = 1; i <= n; i++) {
        if (tab[i] == false) {
            p[i % 2]++;
            pom[i % 2]++;
        }
    }
    
    int wyn = INF;
    for (int l = 0; l < 2; l++) {
        for (int r = 0; r < 2; r++) {
            if (v[1] == 0) {
                v[1] = 2 * n + l;
                p[l]--;
            }
            if (v[n] == 0) {
                v[n] = 2 * n + r;
                p[r]--;
            }
            
            if (p[0] >= 0 || p[1] >= 0) {
                int res = 0;
                int ost = v[1] % 2;
                int poz = 1;
                for (int i = 2; i <= n; i++) {
                    if (v[i] == 0) continue;
                    if (v[i] % 2 == ost) {
                        vp[ost].push_back(i - poz - 1);
                    } else {
                        res++;
                    }
                    ost = v[i] % 2;
                    poz = i;
                }
                
                for (int i = 0; i < 2; i++) {
                    sort(vp[i].begin(), vp[i].end());
                    int j = 0;
                    while (j < vp[i].size() && vp[i][j] <= p[i]) {
                        p[i] -= vp[i][j];
                        j++;
                    }
                    res += (vp[i].size() - j) * 2;
                }
                
                wyn = min(wyn, res);
            }
            
            
            p[0] = pom[0];
            p[1] = pom[1];
            if (v[1] > n) v[1] = 0;
            if (v[n] > n) v[n] = 0;
            vp[0].clear();
            vp[1].clear();
        }
    }
    
    cout << wyn;
    
    
    return 0;
}