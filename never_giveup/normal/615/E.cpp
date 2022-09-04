#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
/*
int n, m;

vector<int> e[100000];

ll answer = 0;

bool v[100000];

pair<ll, ll> d[100000];

void dfs(int st, ll cnt){
    v[st] = 1;
    for (int j = 0; j < (int)e[st].size(); j++){
        int to = e[st][j];
        if (to > st){
            if (!v[to])
                dfs(to, cnt + 1);
            if ((d[to].first * d[to].second > d[st].first * d[st].second) || (d[to].first * d[to].second == d[st].first * d[st].second && d[to].second > d[st].second))
                d[st] = d[to];
        }
    }
    d[st].first++;
    if ((ll)e[st].size() > d[st].first * d[st].second)
        d[st].first = 1, d[st].second = e[st].size();
    answer = max(answer, (d[st].first + cnt - 1) * d[st].second);
}
*/

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    ll N;
    cin >> N;
    if (N == 0){
        cout << "0 0";
        return 0;
    }
    ll n = N;
    ll l = 0, r = sqrt(1e18 / 3.0);
    while (r - l > 1){
        ll m = (l + r) / 2;
        if (m * (m + 1) * 3 < n)
            l = m;
        else
            r = m;
    }
    n -= l * (l + 1) * 3;
    l++;
    if (n <= l)
        n = (n % l == 0 ? l : n % l), cout << 2 * l - n << ' ' << 2 * n;
    else
    if (n <= 2 * l)
        n = (n % l == 0 ? l : n % l), cout << l - 2 * n << ' ' << 2 * l;
    else
    if (n <= 3 * l)
        n = (n % l == 0 ? l : n % l), cout << -l - n << ' ' << 2 * l - 2 * n;
    else
    if (n <= 4 * l)
        n = (n % l == 0 ? l : n % l), cout << -2 * l + n << ' ' << - 2 * n;
    else
    if (n <= 5 * l)
        n = (n % l == 0 ? l : n % l), cout << -l + 2 * n << ' ' << -2 * l;
    else
        n = (n % l == 0 ? l : n % l), cout << l + n << ' ' << -2 * l + 2 * n;
    /*cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
        if (!v[i])
            dfs(i, 1);
    cout << answer;*/
}