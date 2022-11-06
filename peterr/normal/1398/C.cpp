#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int MAX = 1E6;
int pref[MAXN + 1];
int cnts[MAX];

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
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            int dig = s[i] - '0';
            pref[i + 1] = pref[i] + dig;
        }
        fill(cnts, cnts + 10 * n, 0);
        int* origin = cnts + n;
        origin[0]++;
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int bal = pref[i] - i;
            ans += origin[bal];
            origin[bal]++;
        }
        cout << ans << "\n";
    }
    return 0;
}