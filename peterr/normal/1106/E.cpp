#include <bits/stdc++.h>

using namespace std;

struct Envelope
{
    int s, t, d, w;

    bool operator<(const Envelope& other) const
    {
        if (w == other.w)
        {
            return d < other.d;
        }
        return w < other.w;
    }
};

const int MAXN = 1E5;
const int MAXK = 200;
int coins[MAXN + 2];
int nextt[MAXN + 2];
Envelope envs[MAXN];
long long dp[MAXN + 2][MAXK + 1];
bool hasEnv[MAXN + 1];

bool myCmp(const Envelope& a, const Envelope& b)
{
    return a.t < b.t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int s, t, d, w;
        cin >> s >> t >> d >> w;
        Envelope e = {s, t, d, w};
        envs[i] = e;
    }
    sort(envs, envs + k, myCmp);
    /*
    for (int i = 0; i < k; i++)
    {
        cout << envs[i].s << " " << envs[i].t << endl;
    }
    */
    priority_queue<Envelope> pq;
    int index = k - 1;
    coins[n + 1] = 0;
    nextt[n + 1] = n + 1;
    for (int i = n; i >= 1; i--)
    {
        while (index >= 0 && envs[index].t == i)
        {
            pq.push(envs[index--]);
        }
        while (!pq.empty() && pq.top().s > i)
            pq.pop();
        if (!pq.empty())
        {
            hasEnv[i] = true;
            coins[i] = pq.top().w;
            nextt[i] = pq.top().d + 1;
        }
        else
        {
            coins[i] = coins[i + 1];
            nextt[i] = nextt[i + 1];
        }
    }
    /*
    for (int i = 1; i <= n; i++)
        cout << i << " " << coins[i] << " " << nextt[i] << endl;
    */
    for (int i = n; i >= 1; i--)
    {
        dp[i][0] = coins[i] + dp[nextt[i]][0];
    }
    /*
    for (int i = 1; i <= n; i++)
        cout << i << " " << dp[i][0] << endl;
    */
    for (int disturbs = 1; disturbs <= m; disturbs++)
    {
        for (int start = n; start >= 1; start--)
        {
            if (hasEnv[start])
                dp[start][disturbs] = min(coins[start] + dp[nextt[start]][disturbs], dp[start + 1][disturbs - 1]);
            else
                dp[start][disturbs] = dp[start + 1][disturbs];
        }
    }
    cout << dp[1][m] << endl;

    return 0;
}