#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

#ifdef LOCAL
const bool debug = true;
#else
const bool debug = false;
#define cerr if (true) {} else cout
#endif

//#define int long long
#define double long double

const int INF = 100000000; //0000000000LL;
const int mod = 1000000007;

const int baza = 1 << 19;
int drz[baza * 2];
int to_push[baza * 2];

inline void akt(int gdzie, int co) {
    drz[gdzie] += co;
    to_push[gdzie] += co;
}

void add(int co, int pyt_pocz, int pyt_kon, int pocz = 0, int kon = baza, int gdzie = 1) {
    if (pyt_pocz <= pocz && kon <= pyt_kon) {
        akt(gdzie, co);
        return;
    }
    if (pyt_kon <= pocz || kon <= pyt_pocz) {
        return;
    }
    
    int sr = (pocz + kon) / 2;
    add(co, pyt_pocz, pyt_kon, pocz, sr, gdzie * 2);
    add(co, pyt_pocz, pyt_kon, sr, kon, gdzie * 2 + 1);
    drz[gdzie] = min(drz[gdzie * 2], drz[gdzie * 2 + 1]) + to_push[gdzie];
}

/*
int czytaj(int pyt_pocz, int pyt_kon, int pocz = 0, int kon = baza, int gdzie = 1) {
    if (pyt_pocz <= pocz && kon <= pyt_kon) {
        return drz[gdzie];
    }
    if (pyt_kon <= pocz || kon <= pyt_pocz) {
        return INF;
    }
    
    int sr = (pocz + kon) / 2;
    return min( czytaj(pyt_pocz, pyt_kon, pocz, sr, gdzie * 2),
                czytaj(pyt_pocz, pyt_kon, sr, kon, gdzie * 2 + 1)) + to_push[gdzie];
}*/

vector<pair<int, int> > p;
vector<int> q;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    add(INF, 0, baza);
    
    int n;
    cin >> n;
    for (int a, i = 1; i <= n; i++) {
        cin >> a;
        p.push_back({a, i});
    }
    sort(ALL(p));
    reverse(ALL(p));
    
    for (int a, i = 1; i <= n; i++) {
        cin >> a;
        q.push_back(a);
    }
    q.pop_back();
    cout << n << " ";
    
    int gdzie = 0;
    for (int i : q) {
        add(1, 0, i + 1);
        
        while (gdzie < n) {
            int x = p[gdzie].second;
            add(-INF, x, x + 1);
            add(-1, 0, x + 1);
            //cerr << " " << drz[1] << " " << x << endl;
            if (drz[1] >= 0) {
                gdzie++;
            } else {
                add(INF, x, x + 1);
                add(1, 0, x + 1);
                break;
            }
        }
        
        cout << n - gdzie << " ";
    }
    
    return 0;
}/*

*/