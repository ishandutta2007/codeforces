#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3 * 1E5;
char seq[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> seq[i];
    if (n % 2 == 1 || seq[0] == ')' || seq[n-1] == '(')
    {
        cout << ":(";
    }
    else
    {
        seq[0] = '(';
        seq[n-1] = ')';
        int open = 0, close = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (seq[i] == '(')
                open++;
            else if (seq[i] == ')')
                close++;
        }
        int bal = 0;
        bool possible = true;
        for (int i = 1; i < n - 1; i++)
        {
            if (seq[i] == '(')
                bal++;
            else if (seq[i] == ')')
                bal--;
            else
            {
                if (open < (n - 2) / 2)
                {
                    seq[i] = '(';
                    open++;
                    bal++;
                }
                else
                {
                    seq[i] = ')';
                    close++;
                    bal--;
                }
            }
            if (bal < 0)
                possible = false;
        }
        if (possible && bal == 0)
        {
            for (int i = 0; i < n; i++)
                cout << seq[i];
        }
        else
        {
            cout << ":(";
        }
    }
    return 0;
}