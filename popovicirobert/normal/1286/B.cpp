#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int


using namespace std;

const int MAXN = 2000;

vector <int> g[MAXN + 1], ord[MAXN + 1];
int c[MAXN + 1], sol[MAXN + 1], sz;

void dfs(int nod) {
    for(auto it : g[nod]) {
        dfs(it);
        for(auto itr : ord[it]) {
            ord[nod].push_back(itr);
        }
        ord[it].clear();
    }
    sort(ord[nod].begin(), ord[nod].end(), [&](const int &a, const int &b) {
                return sol[a] < sol[b];
         });
    if(ord[nod].size() < c[nod]) {
        cout << "NO";
        exit(0);
    }
    sol[nod] = ++sz;
    for(int i = c[nod]; i < ord[nod].size(); i++) {
        sol[ord[nod][i]] = ++sz;
    }
    ord[nod].push_back(nod);
}

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    int root;
    for(i = 1; i <= n; i++) {
        int par;
        cin >> par >> c[i];
        g[par].push_back(i);
        if(par == 0) {
            root = i;
        }
    }

    dfs(root);

    cout << "YES\n";
    for(i = 1; i <= n; i++) {
        cout << sol[i] << " ";
    }

    return 0;
}