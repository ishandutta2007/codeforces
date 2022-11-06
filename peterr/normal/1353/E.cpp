#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E6;
int one[MAXN];
int zero[MAXN];
int bal[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        fill(one, one + k, 0);
        fill(zero, zero + k, 0);
        int totalOnes = 0;
        int ans = n;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                totalOnes++;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '1')
                bal[i] = 1;
            else
                bal[i] = -1;
            if (i + k < n && bal[i + k] > 0)
                bal[i] += bal[i + k];
            ans = min(ans, totalOnes - bal[i]);
        }
        if (totalOnes == 0 || totalOnes == 1)
        {
            cout << "0\n";
            continue;
        }
        ans = min(ans, totalOnes - 1);
        cout << ans << "\n";
    }
    return 0;
}