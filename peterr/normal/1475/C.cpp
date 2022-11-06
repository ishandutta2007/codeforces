#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int x[MAXN];
int y[MAXN];
int freq1[MAXN + 1];
int freq2[MAXN + 1];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, k;
        cin >> a >> b >> k;
        fill(freq1, freq1 + a + 1, 0);
        fill(freq2, freq2 + b + 1, 0);
        for (int i = 0; i < k; i++)
            cin >> x[i];
        for (int i = 0; i < k; i++)
            cin >> y[i];
        long long ans = (long long) k * (k - 1) / 2;
        for (int i = 0; i < k; i++)
        {
            ans -= freq1[x[i]];
            ans -= freq2[y[i]];
            freq1[x[i]]++;
            freq2[y[i]]++;
        }
        cout << ans << "\n";
    }
    return 0;
}