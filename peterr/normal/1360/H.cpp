#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
string a[MAXN];
bool matches[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        fill(matches, matches + n, true);
        long long k = (1LL << m) - n;
        long long ind = (k - 1) / 2;
        stringstream ans;
        for (int i = m - 1; i >= 0; i--)
        {
            int strInd = m - i - 1;
            int below = 0;
            for (int j = 0; j < n; j++)
            {
                if (matches[j] && a[j][strInd] == '0')
                    below++;
            }
            long long num = (1LL << i) - below;
            char ch;
            if (num <= ind)
            {
                ind -= num;
                ch = '1';
            }
            else
            {
                ch = '0';
            }
            ans << ch;
            for (int j = 0; j < n; j++)
            {
                if (a[j][strInd] != ch)
                    matches[j] = false;
            }
        }
        cout << ans.str() << "\n";
    }
    return 0;
}