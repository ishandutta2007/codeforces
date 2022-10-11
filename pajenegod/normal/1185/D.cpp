#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    if (n<4)
    {
        cout << 1;
        return 0;
    }

    vector<int> B(n);
    for (auto &b : B)
        cin >> b;

    vector<int> index(n);
    for (int i=0; i<n; ++i)
        index[i] = i;

    sort(index.begin(), index.end(), [&B](int i, int j){return B[i] < B[j];});
    sort(B.begin(), B.end());

    vector<int> index2(n);
    for (int i = 0; i< n; ++i)
        index2[index[i]] = i;

    int diff1 = B[1] - B[0];
    int diff2 = B[2] - B[1];
    int diff3 = B[2] - B[0];

    for (int cand : {diff1, diff2, diff3})
    {
        for (int start : {0,1})
        {
            int skip = 0;
            int i = start;
            int val = B[i];
            ++i;
            int count = 1;
            while (i<n)
            {
                while (i<n && B[i] != val + cand)
                {
                    skip = i;
                    ++i;
                }
                val += cand;
                if (i < n)
                    ++count;
                ++i;
            }

            if (count == n-1)
            {
                cout << index[skip] + 1;
                return 0;
            }
            
        }
    }
    cout << -1;
    return 0;

}