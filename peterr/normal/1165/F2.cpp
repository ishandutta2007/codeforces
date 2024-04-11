#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int amt[MAXN + 1];
pair<int, int> offers[MAXN];
int temp[MAXN + 1];

bool check(int days, int n, int m, int sum)
{
    fill(temp + 1, temp + n + 1, 0);
    int money = days;
    int ptr = m - 1;
    int cheap = 0;
    while (ptr >= 0 && offers[ptr].first > days)
        ptr--;
    for (int i = days; i >= 1; i--)
    {
        while (ptr >= 0 && offers[ptr].first == i)
        {
            int type = offers[ptr].second;
            int cnt = max(0, min(min(money, i), amt[type] - temp[type]));
            cheap += cnt;
            temp[type] += cnt;
            money = min(money - cnt, i - cnt);
            ptr--;
        }
    }
    return 2 * sum - cheap <= days;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> amt[i];
        sum += amt[i];
    }
    for (int i = 0; i < m; i++)
        cin >> offers[i].first >> offers[i].second;
    sort(offers, offers + m);
    int ans = -1;
    for (int jump = MAXN; jump > 0; jump /= 2)
    {
        while (!check(ans + jump, n, m, sum))
            ans += jump;
    }
    cout << ans + 1 << endl;
    return 0;
}