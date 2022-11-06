#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> even;
        vector<int> odd;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x & 1)
                even.push_back(x);
            else
                odd.push_back(x);
        }
        for (int x : even)
            cout << x << " ";
        for (int x : odd)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}