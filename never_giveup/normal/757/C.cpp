/*
ID: ramil-p1
PROG: balancing
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 100, inf = 1e9 + 100, mod = 1e9 + 7;

int p[maxn];

set<int> e[2 * maxn];

int sz = 1;

int N, m;

int a[maxn];

vector<int> r[maxn];

bool here[maxn];

ll fact[maxn];

bool cmp(int x, int y){
    return p[x] < p[y];
}

int main(){
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    #endif
    ios::sync_with_stdio(0);
    cin >> N >> m;
    for (int i = 0; i < m; i++)
        p[i] = 0, e[0].insert(i);
    for (int iter = 0; iter < N; iter++){
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
            cin >> a[i], a[i]--, r[i + 1].clear();
        sort(a, a + k);
        int L = 0, R = -1;
        while (L < k){
            while (R < k - 1 && a[R + 1] == a[L])
                R++;
            r[R - L + 1].push_back(a[L]);
            L = R + 1;
        }
        for (int i = 1; i <= k; i++)
        if (r[i].size() > 0){
            sort(r[i].begin(), r[i].end(), cmp);
            L = 0, R = -1;
            while (L < r[i].size()){
                while (R < (int)r[i].size() - 1 && p[r[i][R + 1]] == p[r[i][L]])
                    R++;
                if (e[p[r[i][L]]].size() != R - L + 1){
                    for (int j = L; j <= R; j++)
                        e[p[r[i][j]]].erase(r[i][j]), p[r[i][j]] = sz, e[sz].insert(r[i][j]);
                    sz++;
                }
                L = R + 1;
            }
        }
    }
    fact[0] = 1;
    for (ll i = 1; i <= m; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    ll answer = 1;
    for (int i = 0; i < sz; i++)
        answer = (answer * fact[e[i].size()]) % mod;
    cout << answer;
}