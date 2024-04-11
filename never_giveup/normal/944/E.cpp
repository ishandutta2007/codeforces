#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(1339);

const ll llinf = 2e18 + 100;

const int maxn = 1e5 + 100, maxw = 1e6 + 100, inf = 1e9 + 100, mod = 1e9 + 7, sq = 300, LG = 17;

int n, m;

int a[maxn];

int dp[maxn];

vector<int> q;

int answer;

void prec(){
    q[0] = -inf;
    for (int i = 1; i <= m; i++)
        q[i] = inf;
}

int add(int x){
    int ret = upper_bound(q.begin(), q.end(), x) - q.begin();
    q[ret] = x;
    return ret;
}

int main()
{
    #ifdef ONPC
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    q.resize(m + 1);
    for (int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        a[l - 1]++;
        a[r]--;
    }
    for (int i = 1; i < m; i++)
        a[i] += a[i - 1];
    prec();
    for (int i = 0; i < m; i++)
        dp[i] = add(a[i]);
    prec();
    for (int i = m - 1; i >= 0; i--)
        dp[i] += add(a[i]) - 1;
    for (int i = 0; i < m; i++)
    answer = max(answer, dp[i]);
    if (answer == m){
        int cnt = 0;
        for (int i = 0; i < m; i++)
            if (a[i] > 0)
                cnt++;
        if (cnt == 1)
            cout << m - 1;
        else
            cout << m;
        return 0;
    }
    cout << answer;
}