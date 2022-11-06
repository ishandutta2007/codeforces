#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN];
long long dp[MAXN + 1];
int where[MAXN + 1];

void solve(int l, int r)
{
    if (l > r)
        return;
    int ones = 0;
    for (int i = l; i <= r; i++)
    {
        if (a[i] == 1)
        {
            ones++;
        }
    }
    if (ones == r - l + 1)
    {
        cout << "1";
        for (int i = l + 1; i <= r; i++)
        {
            cout << "+1";
        }
        return;
    }
    if (a[l] == 1)
    {
        cout << "1";
        l++;
        while (a[l] == 1)
        {
            cout << "+1";
            l++;
        }
        cout << "+";
    }
    int oldR = r;
    while (a[r] == 1)
        r--;
    long long prod = 1;
    for (int i = l; i <= r; i++)
    {
        prod *= a[i];
        if (prod >= (long long) 1E16)
        {
            break;
        }
    }
    if (prod >= (long long) 1E16)
    {
        cout << a[l];
        for (int i = l + 1; i <= r; i++)
            cout << "*" << a[i];
    }
    else
    {
        vector<int> positions;
        dp[1] = a[l];
        where[1] = 1;
        positions.push_back(1);
        for (int i = 2; i <= r - l + 1; i++)
        {
            int ind = i + l - 1;
            if (a[ind] == 1)
            {
                dp[i] = dp[i - 1] + 1;
                where[i] = i;
            }
            else
            {
                dp[i] = a[ind] + dp[i - 1];
                where[i] = i;
                long long curProd = a[ind];
                for (int j = (int) positions.size() - 1; j >= 0; j--)
                {
                    curProd *= a[positions[j] + l - 1];
                    if (curProd + dp[positions[j] - 1] > dp[i])
                    {
                        dp[i] = curProd + dp[positions[j] - 1];
                        where[i] = positions[j];
                    }
                }
                positions.push_back(i);
            }
            //cout << "dp " << i << " " << dp[i] << endl;
        }
        vector<char> sym(r - l + 1);
        int cur = r - l + 1;
        while (cur >= 1)
        {
            for (int i = cur - 1; i >= where[cur]; i--)
            {
                sym[i] = '*';
            }
            if (where[cur] - 1 >= 1)
                sym[where[cur] - 1] = '+';
            cur = where[cur] - 1;
        }
        for (int i = 1; i < r - l + 1; i++)
        {
            cout << a[i + l - 1] << sym[i];
        }
        cout << a[r];
    }
    if (oldR > r)
    {
        cout << "+1";
        oldR--;
        while (oldR > r)
        {
            cout << "+1";
            oldR--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;
    bool add = false;
    bool sub = false;
    bool mult = false;
    for (char ch : s)
    {
        if (ch == '+')
            add = true;
        if (ch == '-')
            sub = true;
        if (ch == '*')
            mult = true;
    }
    if (!mult)
    {
        cout << a[0];
        for (int i = 1; i < n; i++)
        {
            if (add)
                cout << "+";
            else
                cout << "-";
            cout << a[i];
        }
        cout << "\n";
    }
    else
    {
        if (!add && !sub)
        {
            cout << a[0];
            for (int i = 1; i < n; i++)
            {
                cout << "*";
                cout << a[i];
            }
            cout << "\n";
        }
        else if (!add)
        {
            cout << a[0];
            for (int i = 1; i < n; i++)
            {
                if (a[i] == 0)
                    cout << "-";
                else
                    cout << "*";
                cout << a[i];
            }
            cout << "\n";
        }
        else //if (!sub)
        {
            int cur = 0;
            for (int i = 0; i < n;)
            {
                if (a[i] == 0)
                {
                    solve(cur, i - 1);
                    if (i)
                        cout << "+";
                    while (i < n && a[i] == 0)
                    {
                        cout << "0";
                        if (i < n - 1)
                            cout << "+";
                        i++;
                    }
                    cur = i;
                }
                else
                    i++;
            }
            if (cur < n)
            {
                solve(cur, n - 1);
            }
        }

    }
    return 0;
}