#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = (int) 1e5;
const int INF = (int) 1e9;

int p[MAXN + 1], key[MAXN + 1];

int l[MAXN + 1], r[MAXN + 1];

pair <int, int> val[MAXN + 1];

int lvl[MAXN + 1];

void dfs1(int nod) {
    if(l[nod] == 0) {
        val[nod] = {key[nod], key[nod]};
        return ;
    }
    lvl[l[nod]] = lvl[nod] + 1;
    lvl[r[nod]] = lvl[nod] + 1;
    dfs1(l[nod]);
    dfs1(r[nod]);
    val[nod].first = val[r[nod]].first;
    val[nod].second = val[l[nod]].second;
}

vector < pair <int, int> > v;

ll sum[MAXN + 1];

void dfs2(int nod, ll s) {
    if(l[nod] == 0) {
        sum[nod] = s;
        v.push_back({key[nod], nod});
        return ;
    }
    dfs2(l[nod], s + val[r[nod]].second);
    v.push_back({key[nod], nod});
    dfs2(r[nod], s + val[l[nod]].first);
}


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k, a;
    ios::sync_with_stdio(false);
    cin >> n;
    int root;
    for(i = 1; i <= n; i++) {
        cin >> p[i] >> key[i];
        if(p[i] == -1)
            root = i;
    }
    for(i = 1; i <= n; i++) {
        if(key[p[i]] > key[i])
            l[p[i]] = i;
        else
            r[p[i]] = i;
    }
    dfs1(root);
    dfs2(root, 0);
    cin >> k;
    for(i = 1; i <= k; i++) {
        cin >> a;
        int rez = 0;
        for(int pas = 1 << 16; pas; pas >>= 1)
            if(rez + pas < v.size() && v[rez + pas].first < a)
                rez += pas;
        int nod;
        if(r[v[rez].second] != 0 && rez + 1 < v.size() && v[rez].first < a)
            nod = v[rez + 1].second;
        else
            nod = v[rez].second;
         cout << setprecision(20) << (double) (1.0 * sum[nod]) / (1.0 * lvl[nod]) << endl;
    }
    //cin.close();
    //cout.close();
    return 0;
}