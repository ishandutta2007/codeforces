#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string y;
        cin >> y;
        bool hasZero = false;
        bool hasEven = false;
        int sum = 0;
        for (int j = 0; j < (int) y.length(); j++)
        {
            int x = y[j] - '0';
            if (x == 0 && !hasZero)
                hasZero = true;
            else if (x % 2 == 0)
                hasEven = true;
            sum += x;
        }
        if (hasZero && hasEven && sum % 3 == 0)
        {
            cout << "red" << endl;
        }
        else
            cout << "cyan" << endl;
    }
    return 0;
}