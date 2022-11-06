#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    stringstream ss;
    if (k == 1)
    {
        ss << 1;
        for (int i = 0; i < n - 1; i++)
            ss << 0;
    }
    else
    {
        int period = (n - k) / 2 + 1;
        for (int i = 0; i < n; i++)
        {
            if (i % period == 0)
                ss << 1;
            else
                ss << 0;
        }
    }
    cout << ss.str() << endl;
    return 0;
}