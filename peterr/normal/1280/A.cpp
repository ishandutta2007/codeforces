#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 1E6;
int a[MAXN + 5];

void add(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        string s;
        cin >> s;
        int len = (int) s.length();
        int p = len;
        for (int i = 0; i < len; i++)
            a[i] = s[i] - '0';
        for (int i = 0; i < x; i++)
        {
            int key = a[i];
            int cut = len - i - 1;
            if (cut < 0)
                cut += MOD;
            if (key == 1)
                continue;
            if (key >= 2)
                add(len, cut);
            if (key == 3)
                add(len, cut);
            int stop = p;
            for (int j = i + 1; j < stop && p < x; j++)
            {
                a[p++] = a[j];
            }
            if (key == 3)
            {
                for (int j = i + 1; j < stop && p < x; j++)
                {
                    a[p++] = a[j];
                }
            }
        }
        cout << len << "\n";
    }
    return 0;
}