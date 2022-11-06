#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> vals;
    int cnt = 0;
    for (int a = 3; a <= 100000; a++)
    {
        if ((long long) a * a % 2 == 0)
            continue;
        long long b = (a * a - 1) / 2;
        long long c = ((long long) a * a + 1) / 2;
        if (c > 1000000000)
            break;
        if (c * c == b * b + (long long) a * a)
        {
            cnt++;
            vals.push_back(c);
            //cout << c << endl;
        }
            //
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ind = -1;
        for (int jump = vals.size(); jump; jump >>= 1)
        {
            while (ind + jump < (int) vals.size() && vals[ind + jump] <= n)
                ind += jump;
        }
        cout << ind + 1 << "\n";
    }
    return 0;
}