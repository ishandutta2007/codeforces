#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int freq[MAXN + 1];

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
        fill(freq + 1, freq + n + 1, 0);
        int same = 0;
        int diff = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (freq[a] == 0)
                diff++;
            freq[a]++;
            same = max(same, freq[a]);
        }
        if (diff - 1 >= same)
            cout << same << "\n";
        else
            cout << min(diff, same - 1) << "\n";
    }
    return 0;
}