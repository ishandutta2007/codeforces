#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int bit[MAXN + 1];
queue<int> loc[26];

void inc(int pos, int amt)
{
    while (pos <= MAXN)
    {
        bit[pos] += amt;
        pos += pos & -pos;
    }
}

int query(int pos)
{
    int ans = 0;
    while (pos)
    {
        ans += bit[pos];
        pos -= pos & -pos;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        int key = s[i] - 'a';
        loc[key].push(i + 1);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int key = s[n - i] - 'a';
        int x = loc[key].front();
        loc[key].pop();
        int adjusted = x + (i - 1) - query(x);
        ans += adjusted - i;
        inc(x, 1);
    }
    cout << ans << "\n";
    return 0;
}