#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    if (n > (long long) k * (k - 1))
    {
        cout << "NO" << endl;
    }
    else
    {
        stringstream ss;
        ss << "YES" << endl;
        int left = 1;
        int right = 2;
        while (n-- > 0)
        {
            ss << left << " " << right << endl;
            if (n-- > 0)
            {
                ss << right << " " << left << endl;
            }
            right++;
            if (right > k)
            {
                left++;
                right = left + 1;
            }
        }
        cout << ss.str();
    }
    return 0;
}