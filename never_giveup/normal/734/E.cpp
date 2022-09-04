#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100;

const ll inf = 1e18 + 100;

int n;

vector<int> e[maxn];

int a[maxn];

int len;

pair<int, int> dfs(int v, int p){
    pair<int, int> ret = make_pair(0, 0);
    for (int i = 0; i < e[v].size(); i++)
        if (e[v][i] != p){
            int x = dfs(e[v][i], v).first;
            if (ret.first < x)
                ret.second = ret.first, ret.first = x;
            else
            if (ret.second < x)
                ret.second = x;
        }
    ret.first += (a[v] != a[p]);
    len = max(len, ret.first + ret.second + 1);
    return ret;
}

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(0, 0);
    cout << len / 2;
}