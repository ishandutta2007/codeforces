#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 100, inf = 2e9 + 100;

int answer = inf;

set<pair<int, int> > q;

int n;

int a[maxn];

vector<int> e[maxn];

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]), q.insert(make_pair(-a[i], i));
    for (int i = 1; i < n; i++){
        int v, u;
        scanf("%d %d", &v, &u);
        v--;
        u--;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    for (int i = 0; i < n; i++){
        int ans = a[i];
        q.erase(make_pair(-a[i], i));
        for (int j = 0; j < e[i].size(); j++){
            int to = e[i][j];
            ans = max(ans, a[to] + 1);
            q.erase(make_pair(-a[to], to));
        }
        if (!q.empty())
            ans = max(ans, -q.begin()->first + 2);
        answer = min(answer, ans);
        q.insert(make_pair(-a[i], i));
        for (int j = 0; j < e[i].size(); j++){
            int to = e[i][j];
            q.insert(make_pair(-a[to], to));
        }
    }
    printf("%d", answer);
}