#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
string s[3];
int ptr[3];
int ans[3 * MAXN];

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
            cin >> s[i];
        ptr[0] = ptr[1] = ptr[2] = 0;
        int cur = 0;
        while (max(ptr[0], max(ptr[1], ptr[2])) < 2 * n)
        {
            int one = 0;
            int zero = 0;
            for (int i = 0; i < 3; i++)
            {
                if (s[i][ptr[i]] == '0')
                    zero++;
                else
                    one++;
            }
            int x = zero > one ? 0 : 1;
            ans[cur++] = x;
            for (int i = 0; i < 3; i++)
            {
                if (s[i][ptr[i]] - '0' == x)
                    ptr[i]++;
            }
        }
        int done = 0;
        for (int i = 0; i < 3; i++)
            done += ptr[i] == 2 * n;
        if (done < 2)
        {
            int ind = 0;
            if (ptr[1] < 2 * n && ptr[1] >= min(ptr[0], ptr[2]))
                ind = 1;
            else if (ptr[2] < 2 * n && ptr[2] >= min(ptr[0], ptr[1]))
                ind = 2;
            while (ptr[ind] < 2 * n)
            {
                ans[cur++] = s[ind][ptr[ind]] - '0';
                ptr[ind]++;
            }
        }
        for (int i = 0; i < cur; i++)
        {
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}