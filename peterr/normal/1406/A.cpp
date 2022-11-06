#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int freq[MAXN + 10];

int solve()
{
    int ans = 0;
    while (freq[ans])
    {
        freq[ans]--;
        ans++;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        fill(freq, freq + MAXN + 1, 0);
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            freq[x]++;
        }
        cout << solve() + solve() << "\n";
    }
    return 0;
}