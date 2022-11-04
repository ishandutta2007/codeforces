#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXVAL = (int) 1e7;
const int MAXN = (int) 1e5;
const int MAXP = (int) 7e5;

inline int lgput(int a, ll b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1)
            ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline int gcd(int a, int b) {
    int r;
    while(b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

struct Query {
    int pos;
    int val;
};

vector <Query> qry[MAXN + 1];
vector <int> g[MAXN + 1];

int vals[MAXN + 1];

int rmq[2 * MAXN + 1][18], first[MAXN + 1], sz;
char lg[2 * MAXN + 1];
int lvl[MAXN + 1];

int low[MAXVAL + 1];
int ind[MAXVAL + 1];

void dfs(int nod) {
    rmq[++sz][0] = nod;
    first[nod] = sz;
    for(auto it : g[nod]) {
        if(!lvl[it]) {
            lvl[it] = lvl[nod] + 1;
            dfs(it);
            rmq[++sz][0] = nod;
        }
    }
}

inline void prec() {
    lvl[1] = 1;
    dfs(1);
    for(int bit = 1; (1 << bit) <= sz; bit++) {
        for(int i = 1; i + (1 << bit) <= sz + 1; i++) {
            int a = rmq[i][bit - 1], b = rmq[i + (1 << (bit - 1))][bit - 1];
            if(lvl[a] < lvl[b])
                rmq[i][bit] = a;
            else
                rmq[i][bit] = b;
        }
    }
    for(int i = 2; i <= sz; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    for(int i = 2; i <= MAXVAL; i++) {
        if(low[i] == 0) {
            for(int j = i; j <= MAXVAL; j += i) {
                low[j] = i;
            }
        }
    }
    int cnt = 0;
    for(int i = 2; i <= MAXVAL; i++) {
        if(low[i] == i) {
            ind[i] = ++cnt;
        }
    }
}

inline int get(int x, int y) {
    x = first[x];
    y = first[y];
    if(x > y) {
        swap(x, y);
    }
    int bit = lg[y - x + 1];
    if(lvl[rmq[x][bit]] < lvl[rmq[y - (1 << bit) + 1][bit]])
        return rmq[x][bit];
    return rmq[y - (1 << bit) + 1][bit];
}

int fr[MAXP][28];
int sol[MAXN + 1];

inline void decompose(int val, char sign) {
    while(val > 1) {
        int aux = low[val];
        int cnt = 0;
        while(aux == low[val]) {
            cnt++;
            val /= aux;
        }
        fr[ind[aux]][cnt] += sign;
    }
}

void solve(int nod) {
    decompose(vals[nod], 1);
    for(auto it : qry[nod]) {
        int val = it.val;
        while(val > 1) {
            int aux = low[val];
            int cnt = 0;
            while(low[val] == aux) {
                val /= aux;
                cnt++;
            }
            ll pw = aux;
            int cur = 1, sum = 0;
            while(pw <= MAXVAL) {
                sum += min(cur, cnt) * fr[ind[aux]][cur];
                cur++;
                pw *= aux;
            }
            if(it.pos > 0) {
                sol[it.pos] = (1LL * sol[it.pos] * lgput(aux, sum)) % MOD;
            }
            else {
                int prd = lgput(aux, 1LL * sum * (MOD - 2));
                sol[-it.pos] = (1LL * sol[-it.pos] * prd) % MOD;
                sol[-it.pos] = (1LL * sol[-it.pos] * prd) % MOD;
            }
        }
    }
    for(auto it : g[nod]) {
        if(lvl[it] > lvl[nod]) {
            solve(it);
        }
    }
    decompose(vals[nod], -1);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x, y, val, q;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    prec();
    for(i = 1; i <= n; i++) {
        cin >> vals[i];
    }
    cin >> q;
    for(i = 1; i <= q; i++) {
        cin >> x >> y >> val;
        int nod = get(x, y);
        //printf("%d\n" ,nod);
        qry[nod].push_back({-i, val});
        qry[x].push_back({i, val});
        qry[y].push_back({i, val});
        sol[i] = gcd(val, vals[nod]);
    }
    solve(1);
    for(i = 1; i <= q; i++) {
        cout << sol[i] << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}