#include <bits/stdc++.h>

using namespace std;

int freq[3];

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
        for (int i = 0; i < 3; i++)
            freq[i] = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            freq[x % 3]++;
        }
        int ans = 0;
        n /= 3;
        for (int i = 0; i < 10; i++)
        {
            ans += max(0, freq[i % 3] - n);
            freq[(i + 1) % 3] += max(0, freq[i % 3] - n);
            freq[i % 3] -= max(0, freq[i % 3] - n);
        }
        cout << ans << "\n";
    }
    return 0;
}