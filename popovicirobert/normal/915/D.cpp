#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 34

using namespace std;

const int MAXN = 500;
const int MAXM = (int) 1e5;

vector <int> g[MAXN + 1];

int x[MAXM + 1], y[MAXM + 1];

int ok[MAXN + 1];
bool flag;

vector <int> edge;

void dfs(int nod) {
    ok[nod] = 1;
    edge.push_back(nod);
    for(auto it : g[nod]) {
        if(flag == 0) {
            if(ok[it] == 0) {
                dfs(it);
            }
            else if(ok[it] == 1) {
                flag = 1;
                edge.push_back(it);
            }
        }
    }
    ok[nod] = 2;
    if(flag == 0)
        edge.pop_back();
}

int a, b;

void dfs1(int nod) {
    ok[nod] = 1;
    for(auto it : g[nod]) {
        if(flag == 0 && !(a == nod && b == it)) {
            if(ok[it] == 0) {
                dfs1(it);
            }
            else if(ok[it] == 1) {
                flag = 1;
            }
        }
    }
    ok[nod] = 2;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= m; i++) {
        cin >> x[i] >> y[i];
        g[x[i]].push_back(y[i]);
    }
    for(i = 1; i <= n && flag == 0; i++) {
        if(ok[i] == 0) {
            dfs(i);
        }
    }
    if(flag == 0) {
        cout << "YES";
        return 0;
    }
    /*for(auto it : edge)
        printf("%d " ,it);
        printf("\n");*/
    int sz = edge.size();
    for(i = sz - 2; i >= 0; i--) {
        a = edge[i], b = edge[i + 1];
        //printf("%d %d\n" ,a,b);
        if(i == sz - 2 || b != edge.back()) {
            memset(ok, 0, sizeof(ok));
            flag = 0;
            for(int j = 1; j <= n && flag == 0; j++) {
                if(ok[j] == 0)
                    dfs1(j);
            }
            if(flag == 0) {
                cout << "YES";
                return 0;
            }
        }
        else
            break;
    }
    cout << "NO";
    //cin.close();
    //cout.close();
    return 0;
}