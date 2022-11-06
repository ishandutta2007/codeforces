#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> vec;
        for (int i = 1; i <= n; i++)
        {
            if (i > k)
                vec.push_back(i);
            else if (i < k && k - i <= i)
            {
                vec.push_back(i);
            }
        }
        cout << vec.size() << "\n";
        for (int x : vec)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}