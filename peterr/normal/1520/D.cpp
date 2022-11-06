#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            freq[x - i]++;
        }
        long long ans = 0;
        for (auto it : freq)
        {
            ans += (long long) it.second * (it.second - 1) / 2;
        }
        cout << ans << "\n";
    }
    return 0;
}