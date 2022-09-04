#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e3 + 100, inf = 1e9 + 100;

int n;

vector<int> e[20];

int lg;

void go(int l, int r, int it){
    if (l == r)
        return;
    lg = it;
    int m = (l + r) / 2;
    for (int i = l; i <= m; i++)
        e[2 * it].push_back(i);
    for (int i = m + 1; i <= r; i++)
        e[2 * it + 1].push_back(i);
    go(l, m, it + 1);
    go(m + 1, r, it + 1);
}

int answer[maxn];

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        answer[i] = 1e9;
    go(0, n - 1, 0);
    for (int i = 0; i < 20; i++)
    if (!e[i].empty()){
        cout << e[i].size() << endl;
        for (int j = 0; j < e[i].size(); j++)
            cout << e[i][j] + 1 << ' ';
        cout << endl;
        for (int j = 0; j < n; j++){
            int x;
            cin >> x;
            bool is = 0;
            for (int f = 0; f < e[i].size() && !is; f++)
                if (e[i][f] == j)
                    is = 1;
            if (!is)
                answer[j] = min(answer[j], x);
        }
    }
    cout << -1 << endl;
    for (int i = 0; i < n; i++)
        cout << answer[i] << ' ';
    cout << endl;
}