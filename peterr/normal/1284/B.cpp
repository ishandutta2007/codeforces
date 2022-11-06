#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
const int MAXS = 1E6 + 1;
bool isGood[MAXN];
pair<int, int> mm[MAXN];
int bit[MAXS + 1];

void inc(int pos, int amt)
{
    while (pos <= MAXS)
    {
        bit[pos] += amt;
        pos += pos & -pos;
    }
}

int query(int pos)
{
    int ans = 0;
    while (pos > 0)
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
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        for (int j = 0; j < l; j++)
        {
            int x;
            cin >> x;
            x++;
            if (j == 0)
            {
                mm[i].first = mm[i].second = x;
            }
            else
            {
                if (x > mm[i].first)
                {
                    isGood[i] = true;
                }
                mm[i].first = min(mm[i].first, x);
                mm[i].second = max(mm[i].second, x);
            }
        }
        if (!isGood[i])
        {
            inc(mm[i].second, 1);
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!isGood[i])
        {
            ans += query(mm[i].first);
        }
    }
    cout << (long long) n * n - ans << endl;

    return 0;
}