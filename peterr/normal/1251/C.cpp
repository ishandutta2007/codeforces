#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        int n = (int) a.length();
        vector<int> even, odd;
        for (int i = 0; i < n; i++)
        {
            if ((a[i] - '0') % 2 == 0)
                even.push_back(a[i] - '0');
            else
                odd.push_back(a[i] - '0');
        }
        stringstream ss;
        int i = 0, j = 0;
        while (i < even.size() && j < odd.size())
        {
            if (even[i] < odd[j])
                ss << even[i++];
            else
                ss << odd[j++];
        }
        while (i < even.size())
            ss << even[i++];
        while (j < odd.size())
            ss << odd[j++];
        cout << ss.str() << endl;
    }
    return 0;
}