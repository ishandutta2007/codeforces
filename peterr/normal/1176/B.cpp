#include <bits/stdc++.h>

using namespace std;

int freq[3];

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
            long long a;
            cin >> a;
            freq[a%3]++;
        }
        int ans = freq[0] + min(freq[1], freq[2]);
        if (freq[1] > freq[2])
        {
            ans += (freq[1] - freq[2]) / 3;
        }
        else
        {
            ans += (freq[2] - freq[1]) / 3;
        }
        cout << ans << endl;
        fill(freq, freq + 3, 0);
    }
    return 0;
}