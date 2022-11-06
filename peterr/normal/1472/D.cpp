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
        int n;
        cin >> n;
        vector<int> even;
        vector<int> odd;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x & 1)
                odd.push_back(x);
            else
                even.push_back(x);
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        long long a = 0;
        long long b = 0;
        bool alice = 1;
        while (n--)
        {
            if (even.empty())
            {
                if (!alice)
                    b += odd.back();
                odd.pop_back();
            }
            else if (odd.empty())
            {
                if (alice)
                    a += even.back();
                even.pop_back();
            }
            else if (odd.back() > even.back())
            {
                if (!alice)
                    b += odd.back();
                odd.pop_back();
            }
            else
            {
                if (alice)
                    a += even.back();
                even.pop_back();
            }
            alice = !alice;
        }
        if (a > b)
            cout << "Alice\n";
        else if (b > a)
            cout << "Bob\n";
        else
            cout << "Tie\n";
    }
    return 0;
}