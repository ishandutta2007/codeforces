#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
const int MAXN = 105;

int n, m;
LL inp[MAXN][MAXN];

LL gcd(LL a, LL b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m;

    LL ma = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> inp[i][j];
            ma = max(ma, inp[i][j]);
        }
    }

    if (ma == 0) {
        cout << "YES\n1\n";
        for (int i = 0; i < n; ++i) {
            cout << "0 ";
        }
        cout << endl;
        for (int i = 0; i < m; ++i) {
            cout << "0 ";
        }            
        cout << endl;
        return 0;
    }

    LL mod = -1;

    /*
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            vector <int> now;
            for (int k = 0; k < m; ++k) {
                now.puba(inp[i][k] - inp[j][k]);
            }
            sort(bend(now));
            now.resize(unique(bend(now)) - now.begin());
            if (szof(now) > 1) { 
                if (mod == -1) {
                    mod = now[1] - now[0];
                }
                for (int k = 0; k < szof(now); ++k) {
                    for (int k2 = k + 1; k2 < szof(now); ++k2) {
                        mod = gcd(mod, now[k2] - now[k]);
                        if (mod <= ma) {
                            cout << "NO\n";
                            return 0;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            vector <int> now;
            for (int k = 0; k < n; ++k) {
                now.puba(inp[k][i] - inp[k][j]);
            }
            sort(bend(now));
            now.resize(unique(bend(now)) - now.begin());
            if (szof(now) > 1) { 
                if (mod == -1) {
                    mod = now[1] - now[0];
                }
                for (int k = 0; k < szof(now); ++k) {
                    for (int k2 = k + 1; k2 < szof(now); ++k2) {
                        mod = gcd(mod, now[k2] - now[k]);
                        if (mod <= ma) {
                            cout << "NO\n";
                            return 0;
                        }
                    }
                }
            }
        }
    }*/

    vector <LL> now;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            now.puba(inp[i][j] - (inp[i][0] + inp[0][j]));
        }
    }
    sort(bend(now));
    now.resize(unique(bend(now)) - now.begin());
    if (szof(now) > 1) { 
        if (mod == -1) {
            mod = now[1] - now[0];
        }
        for (int k = 0; k < szof(now); ++k) {
            for (int k2 = k + 1; k2 < szof(now); ++k2) {
                mod = gcd(mod, now[k2] - now[k]);
                if (mod <= ma) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    
    if (mod == -1) {
        mod = ma + 1;
    }

    if (mod <= ma) {
        cout << "NO\n";
        return 0;
    }
    /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ()
        }
    }*/

    vector <LL> a;
    vector <LL> b;

    for (int i = 0; i < n; ++i) {
        a.puba(inp[i][0]);
    }
    b.puba(0);    
    for (int i = 1; i < m; ++i) {
        b.puba(((inp[0][i] - inp[0][0]) % mod + mod) % mod);
    }
    /*
    bool flag = false;
    while (clock() < CLOCKS_PER_SEC * 0.8) {
        bool nf = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((a[i] + b[j]) % mod != inp[i][j]) {
                    nf = false;
                    break;
                }
            }
            if (!nf) {
                break;
            }
        }
        if (nf) {
            flag = true;
            break;
        }
        for (int i = 0; i < n; ++i) {
            a[i] = (a[i] + 1) % mod;
        }
        for (int i = 0; i < m; ++i) {
            b[i] = (b[i] + mod - 1) % mod;
        }        
    }

    if (!flag) {
        cout << "NO\n";
        return 0;
    }
    */
    cout << "YES\n";
    
    cout << mod << endl;
    
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < m; ++i) {
        cout << b[i] << " ";
    } 

    return 0;
}