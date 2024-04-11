#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        if (x > 45)
            cout << "-1\n";
        else
        {
            vector<int> dig;
            int cur = 9;
            while (cur >= 1 && x > cur)
            {
                dig.push_back(cur);
                x -= cur;
                cur--;
            }
            if (x)
                dig.push_back(x);
            sort(dig.begin(), dig.end());
            for (int d : dig)
                cout << d;
            cout << "\n";
        }
    }
    return 0;
}