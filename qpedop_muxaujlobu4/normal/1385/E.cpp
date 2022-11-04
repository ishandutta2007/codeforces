#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<random>
#define double long double
#define int long long
using namespace std;
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
const long long INF = 8e17;
//const long long m = 1000000007;
const int Y = 200100;
bool cer;
vector<int>Ed[Y];
vector<int>tip;
vector<char>used;
vector<pair<int, int>>reb;
vector<int>tm;
int tieR = 0;
void dfs(int i) {
    used[i] = 1;
    for (auto x : Ed[i]) {
        if (used[x] == 1)cer = true;
        else if (used[x] == 0)dfs(x);
    }
    used[i] = 2;
    tm[i] = tieR++;
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    //freopen("flow.in", "r", stdin);
   // freopen("flow.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cer = false;
        used.assign(n + 1, 0);
        tip.assign(m, 0);
        reb.assign(m, { 0,0 });
        tm.assign(n + 1, 0);
        tieR = 0;
        for (int i = 1; i <= n; ++i)Ed[i].clear();
        for (int i = 0; i < m; ++i) {
            int tt, a, b;
            cin >> tt >> a >> b;
            reb[i] = { a,b };
            tip[i] = tt;
            if (tt == 1)Ed[a].push_back(b);
        }
        for (int i = 1; i <= n; ++i)if (used[i] == 0)dfs(i);
        if (cer)cout << "NO\n";
        else {
            cout << "YES\n";
            for (auto x : reb) {
                if (tm[x.first] < tm[x.second])swap(x.first, x.second);
                cout << x.first << " " << x.second << "\n";
            }
        }
    }
    return 0;
}
/*
8 8
7 8 1 1
1 2 1 -1
2 3 1 -1
3 4 1 -1
4 1 1 -1
2 5 1 -10
5 6 1 -10
6 2 1 -10
7 8
*/
/* Fri Jul 10 2020 08:35:42 GMT+0300 (,  ) */

/* Sat Jul 11 2020 18:41:06 GMT+0300 (,  ) */

/* Sat Jul 11 2020 19:52:11 GMT+0300 (,  ) */