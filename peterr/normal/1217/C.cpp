#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 2E5;
int zeros[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = (int) s.length();
        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] == '1')
                zeros[i] = 0;
            else
                zeros[i] = zeros[i - 1] + 1;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                continue;
            int num = 0;
            for (int j = 0; i + j < n && j < 22; j++)
            {
                num *= 2;
                if (s[i + j] == '1')
                    num++;
                if (j + 1 <= num && zeros[i] + j + 1 >= num)
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}