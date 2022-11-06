#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2 * 1E5;
pair<int, int> b[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b, b + n);
    if (n == 2 || n == 3)
    {
        cout << 1;
    }
    else
    {
        int c[3] = {b[1].first - b[0].first, b[2].first - b[0].first, b[2].first - b[1].first};
        int error[3] = {0, 0, 0};
        for (int j = 0; j < 3; j++)
        {
            bool skip = false;
            for (int i = 1; i < n; i++)
            {
                if (i == 1 && j == 1)
                {
                    skip = true;
                    i++;
                }
                else if (i == 1 && j == 2)
                {
                    i++;
                }
                if (skip)
                {
                    skip = false;
                    if (b[i].first - b[i-2].first != c[j])
                    {
                        error[j]++;
                        skip = true;
                    }
                }
                else if (b[i].first - b[i-1].first != c[j])
                {
                    error[j]++;
                    skip = true;
                }
            }
        }
        if (error[1] == 0)
        {
            cout << b[1].second + 1;
        }
        else if (error[2] == 0)
        {
            cout << b[0].second + 1;
        }
        else if (error[0] == 0)
        {
            cout << 1;
        }
        else if (error[0] == 1)
        {
            for (int i = 1; i < n; i++)
            {
                if (b[i].first - b[i-1].first != c[0])
                {
                    cout << b[i].second + 1;
                    break;
                }
            }
        }
        else
        {
            cout << -1;
        }
    }
    return 0;
}