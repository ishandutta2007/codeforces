#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair <int, int> pii;
const int MAXN = 1e5 + 5;

struct number {
    int a, b;
    number() {
        a = 0;
        b = 1;
    }
    number(int _a, int _b) {
        a = _a;
        b = _b;
    }
};

bool operator<(number n1, number n2) {
    return (ll) n1.a * (ll) n2.b < (ll) n2.a * (ll) n1.b;
}

int n, m, k;
bool iscastle[MAXN];
vector <int> graph[MAXN];
int degree[MAXN];

set <pair <number, int> > rest;

bool used[MAXN];
int now[MAXN];

int main() {    
    //freopen("inp", "r", stdin);
    //freopen(".out", "w", stdout);

    //cin >> n >> m >> k;
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < k; ++i) {
        int num;
        scanf("%d", &num);
        --num;
        iscastle[num] = true;
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a;--b;
        ++degree[a];
        ++degree[b];
        if (!iscastle[a] && !iscastle[b]) {
            //cerr << "add " << a << " " << b << endl;
            graph[a].puba(b);
            graph[b].puba(a);
        }
    }

    vector <int> good;
    for (int i = 0; i < n; ++i) {
        if (!iscastle[i]) {
            rest.insert(mapa(number(szof(graph[i]), degree[i]), i));
            now[i] = szof(graph[i]);
            good.puba(i);
        }
    }

    number best = number(-1, 1);
    int mem = -1;
    for (int i = 0; i < szof(good); ++i) {
        //cerr << i << endl;
        pair <number, int> p = *rest.begin();
        used[p.ss] = true;
        rest.erase(p);
        if (best < p.ff) {
            best = p.ff;
            mem = i;
        }
        //cerr << p.ss << endl;
        for (int j = 0; j < szof(graph[p.ss]); ++j) {
            //cerr << "@" << endl;
            //cerr << p.ss << " " << j << " " << graph[p.ss][j] << endl;
            if (!used[graph[p.ss][j]]) {
                rest.erase(mapa(number(now[graph[p.ss][j]], degree[graph[p.ss][j]]), graph[p.ss][j]));
                now[graph[p.ss][j]]--;
                rest.insert(mapa(number(now[graph[p.ss][j]], degree[graph[p.ss][j]]), graph[p.ss][j]));
            }
        }
    }
    
    memset(used, 0, sizeof used);

    for (int i = 0; i < n; ++i) {
        if (!iscastle[i]) {
            rest.insert(mapa(number(szof(graph[i]), degree[i]), i));
            now[i] = szof(graph[i]);
            //good.puba(i);
        }
    }

    //number best = number(-1, 1);
    //int mem = -1;
    for (int i = 0; i < mem; ++i) {
        pair <number, int> p = *rest.begin();
        used[p.ss] = true;
        rest.erase(p);
        if (best < p.ff) {
            best = p.ff;
            mem = i;
        }
        //cerr << p.ss << endl;
        for (int j = 0; j < szof(graph[p.ss]); ++j) {
            //cerr << "@" << endl;
            //cerr << p.ss << " " << j << " " << graph[p.ss][j] << endl;
            if (!used[graph[p.ss][j]]) {
                rest.erase(mapa(number(now[graph[p.ss][j]], degree[graph[p.ss][j]]), graph[p.ss][j]));
                now[graph[p.ss][j]]--;
                rest.insert(mapa(number(now[graph[p.ss][j]], degree[graph[p.ss][j]]), graph[p.ss][j]));
            }
        }
    }


    vector <int> ans;
    for (int i = 0; i < n; ++i) {
        if (!used[i] && !iscastle[i]) {
            ans.puba(i);
        }
    }

    printf("%d\n", szof(ans));

    for (int i = 0; i < szof(ans); ++i) {
        printf("%d ", ans[i] + 1);
    }
    printf("\n");
                                
    return 0;
}