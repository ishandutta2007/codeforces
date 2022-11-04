#include <bits/stdc++.h>
#define lsb(x)
#define ll long long

using namespace std;

const int MAXN = (int) 1e6;

int cst[MAXN + 1];

int n;

vector <int> v[MAXN + 1];
vector <ll> sp[MAXN + 1];

inline void combine(int nod) {
    int sz1 = 0, sz2 = 0;
    if(2 * nod <= n)
        sz1 = v[2 * nod].size();
    if(2 * nod + 1 <= n)
        sz2 = v[2 * nod + 1].size();
    int i = 0, j = 0;
    while(i < sz1 && j < sz2) {
        if(v[2 * nod][i] + cst[2 * nod] < v[2 * nod + 1][j] + cst[2 * nod + 1]) {
            v[nod].push_back(v[2 * nod][i] + cst[2 * nod]);
            i++;
        }
        else {
            v[nod].push_back(v[2 * nod + 1][j] + cst[2 * nod + 1]);
            j++;
        }
    }
    while(i < sz1) {
        v[nod].push_back(v[2 * nod][i] + cst[2 * nod]);
        i++;
    }
    while(j < sz2) {
        v[nod].push_back(v[2 * nod + 1][j] + cst[2 * nod + 1]);
        j++;
    }
}

void dfs(int nod, int val) {
    if(2 * nod <= n)
        dfs(2 * nod, val + cst[2 * nod]);
    if(2 * nod + 1 <= n)
        dfs(2 * nod + 1, val + cst[2 * nod + 1]);
    v[nod].push_back(0);
    combine(nod);
    ll sum = 0;
    for(int i = 0; i < v[nod].size(); i++) {
        sum += v[nod][i];
        sp[nod].push_back(sum);
    }
}

int main(){
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i < n; i++) {
        cin >> cst[i + 1];
    }
    dfs(1, 0);
    while(m > 0) {
        m--;
        int nod, dst;
        cin >> nod >> dst;
        ll ans = 0;
        int pos = upper_bound(v[nod].begin(), v[nod].end(), dst) - v[nod].begin();
        if(pos > 0) {
            ans = 1LL * pos * dst - sp[nod][pos - 1];
        }
        while(nod / 2 > 0 && dst > cst[nod]) {
            int aux = nod / 2;
            dst -= cst[nod];
            ans += dst;
            for(int p = 0; p < 2; p++) {
               if(2 * aux + p <= n && 2 * aux + p != nod && dst >= cst[2 * aux + p]) {
                   pos = upper_bound(v[2 * aux + p].begin(), v[2 * aux + p].end(), dst - cst[2 * aux + p]) - v[2 * aux + p].begin();
                   if(pos > 0)
                       ans += 1LL * pos * (dst - cst[2 * aux + p]) - sp[2 * aux + p][pos - 1];
               }
            }
            nod /= 2;
        }
        cout << ans << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}