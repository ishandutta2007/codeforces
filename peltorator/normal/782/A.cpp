#include <bits/stdc++.h>

using namespace std;

vector<int> used;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    used.assign(n + 1, 0);
    int ans = 0, cur = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        int x;
        cin >> x;
        if (used[x])
            cur--;
        else
        {
            cur++;
            ans = max(ans, cur);
            used[x] = 1;
        }
    }
    cout << ans;
    return 0;
}