#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E4;
int res[MAXN + 1];

int query(int t, int i, int j, int x)
{
    /*
    vector<int> test = {0, 2, 1, 9, 8, 4, 3, 6, 7, 5};
    if (t == 1)
        return max(min(x, test[i]), min(x + 1, test[j]));
    else
        return min(max(x, test[i]), max(x + 1, test[j]));
    */
    cout << "? " << t << " " << i << " " << j << " " << x << endl;
    int ans;
    cin >> ans;
    return ans;
}

bool isOne(int i, int j)
{
    return query(2, i, j, 1) == 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ind = -1;
        for (int i = 1; i <= n; i += 2)
        {
            if (i == n)
            {
                ind = i;
                break;
            }
            if (query(2, i, i + 1, 1) <= 2)
            {
                if (isOne(i, i + 1))
                    ind = i;
                else if (isOne(i + 1, i))
                    ind = i + 1;
                if (ind != -1)
                    break;
            }
        }
        fill(res + 1, res + n + 1, -1);
        res[ind] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (i == ind)
                continue;
            res[i] = query(1, ind, i, n - 1);
        }
        cout << "! ";
        for (int i = 1; i <= n; i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}