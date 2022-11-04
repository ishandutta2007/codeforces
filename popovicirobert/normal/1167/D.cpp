#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

vector <int> g[MAXN + 1];
vector <int> pos;
string sol;

void dfs(int nod, int col) {
    sol[nod] = sol[pos[nod]] = col + '0';
    for(auto it : g[nod]) {
        dfs(it, col ^ 1);
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string str;

    cin >> n >> str;
    str = " " + str;

    pos.resize(n + 1);
    stack <int> stk;
    stk.push(0);

    for(i = 1; i <= n; i++) {
        if(str[i] == '(') {
            stk.push(i);
        }
        else {
            int son = stk.top();
            pos[son] = i;
            stk.pop();
            g[stk.top()].push_back(son);
        }
    }

    sol.resize(n + 1);
    dfs(0, 0);

    for(i = 1; i <= n; i++) {
        cout << sol[i];
    }

    //cin.close();
    //cout.close();
    return 0;
}