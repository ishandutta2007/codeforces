#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 1E5;
ll strings[MAXN];
ll gaps[MAXN - 1];
ll prefix[MAXN - 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> strings[i];
    }
    sort(strings, strings + n);
    for (int i = 0; i < n - 1; i++)
    {
        gaps[i] = strings[i + 1] - strings[i];
    }
    sort(gaps, gaps + n - 1);
    prefix[0] = gaps[0];
    for (int i = 1; i < n - 1; i++)
    {
        prefix[i] = gaps[i] + prefix[i - 1];
    }
    cin >> q;
    stringstream ss;
    for (int i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;
        ll dist = r - l;
        int index = -1;
        for (ll jump = n / 2 + 1; jump > 0; jump /= 2)
        {
            while (index + jump < n - 1 && dist >= gaps[index + jump])
                index += jump;
        }
        ll ans = 0;
        if (index != -1)
            ans += prefix[index];
        ans += (n - index - 1) * (dist + 1);
        ss << ans << " ";
    }
    cout << ss.str();
    return 0;
}