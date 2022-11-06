#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E8;
bool color[MAXN];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == '1')
            color[i] = true;
    }
    if (n <= 3)
    {
        cout << "tokitsukaze";
    }
    else if (n == k)
    {
        cout << "tokitsukaze";
    }
    else
    {
        int first1 = n, first0 = n, last1 = 0, last0 = 0;
        for (int i = 0; i < n; i++)
        {
            if (color[i])
            {
                first1 = min(first1, i);
                last1 = max(last1, i);
            }
            else
            {
                first0 = min(first0, i);
                last0 = max(last0, i);
            }
        }
        if (last1 - first1 + 1 <= k || last0 - first0 + 1 <= k)
        {
            cout << "tokitsukaze";
        }
        else
        {
            if (k * 2 < n)
            {
                cout << "once again";
            }
            else
            {
                bool tie = false;
                for (int i = 2; i + k < n; i++)
                {
                    if (color[i - 1] != color[0])
                        tie = true;
                    if (color[n - i] != color[n - 1])
                        tie = true;
                }
                if (tie)
                {
                    cout << "once again";
                }
                else
                {
                    cout << "quailty";
                }

            }
        }
    }
    return 0;
}