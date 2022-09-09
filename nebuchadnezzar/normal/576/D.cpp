#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME aplusb

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int MAXN = 155;

bitset <MAXN> zero;

struct matrix {
    bitset <MAXN> m[MAXN];
    matrix() {
        memset(m, 0, sizeof m);
    }
    matrix operator*(matrix n) {
        matrix ret;
        matrix tmp;
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                tmp.m[i][j] = n.m[j][i];
            }
        }
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                ret.m[i][j] = (m[i] & tmp.m[j]) != zero;
            }
        }
        return ret;
    }
} ONE;

matrix m_pow(matrix m, int a) {
    if (a == 0) {
        return ONE;
    }
    matrix ret = m_pow(m, a / 2);
    ret = ret * ret;
    if (a & 1) {
        ret = ret * m;
    }
    return ret;
}

int n, m;
bool used[MAXN];

int main() {        
    for (int i = 0; i < MAXN; ++i) {
        ONE.m[i][i] = 1;
    }
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    matrix cond;
    cond.m[0][0] = 1;
    matrix step;    

    scanf("%d%d", &n, &m);

    step.m[n - 1][n - 1] = 1;

    vector <pii> v;
    vector <tuple<int, int, int>> inp;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        --a; --b;
        inp.puba(make_tuple(a, b, c));
        v.puba({c, i});
    }
    
    sort(bend(v));

    int t = v.back().ff + 205;
    inp.puba(make_tuple(MAXN - 1, MAXN - 1, t));
    v.puba({t, m});

    int prev = 0;
    for (auto p: v) {
        int a, b, c;
        tie(a, b, c) = inp[p.ss];
        //cerr << a << " " << b << " " << c << endl;        
        if (c > prev) {
            matrix now = cond * m_pow(step, c - prev);
            if (now.m[0][n - 1]) {
                queue <pii> q;
                memset(used, 0, sizeof used);
                for (int i = 0; i < n; ++i) {
                    if (cond.m[0][i]) {
                        q.push({i, 0});
                        used[i] = true;
                        //cerr << i << " ";
                    }                
                }
                //cerr << endl;

                while (szof(q)) {
                    pii p = q.front();
                    //cerr << p.ff << " " << p.ss << endl;
                    if (p.ss > c - prev) {
                        break;
                    }
                    q.pop();
                    if (p.ff == n - 1) {
                        cout << p.ss + prev << endl;
                        return 0;
                    }
                    for (int i = 0; i < n; ++i) {
                        if (step.m[p.ff][i] && !used[i]) {
                            used[i] = true;
                            q.push({i, p.ss + 1});
                        }
                    }
                }
            }
            
            cond = now;
            prev = c;
            //cerr << "upd" << endl;
        }
        step.m[a][b] = 1;
        /*
        cerr << "step:\n";
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                cerr << step.m[j][k] << " ";
            }
            cerr << endl;
        }
        cerr << "cond:\n";
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                cerr << cond.m[j][k] << " ";
            }
            cerr << endl;
        }
        */
    }
    cout << "Impossible\n";
    return 0;
}