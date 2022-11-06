#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2 * 1E5;
int freq[MAXN + 1];

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            freq[a]++;
        }
        sort(freq + 1, freq + n + 1);
        int ans = 0;
        int prev = 2 * 1e5 + 5;
        int index = n;
        while (prev > 1 && index >= 1 && freq[index] > 0)
        {
            if (freq[index] >= prev)
            {
                ans += prev - 1;
                prev = prev - 1;
            }
            else
            {
                ans += freq[index];
                prev = freq[index];
            }
            index--;
        }
        cout << ans << endl;
        fill(freq + 1, freq + n + 1, 0);
    }
    return 0;
}