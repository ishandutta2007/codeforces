#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        string ans = "{";
        int num = 0;
        for (int i = 1; i <= n; i++)
        {
            string x = s.substr(i - 1);
            int mod = (n - i + 1) % 2;
            if (i > 1)
            {
                x += s.substr(0, i - 1);
                if (mod)
                {
                    for (int j = 0; j < (i - 1) / 2; j++)
                    {
                        swap(x[n - i + 1 + j], x[n - j - 1]);
                    }
                }
            }
            //cout << x << endl;
            if (x < ans)
            {
                ans = x;
                num = i;
            }

        }
        cout << ans << "\n";
        cout << num << "\n";
    }
    return 0;
}