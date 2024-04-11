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
        long long k;
        cin >> k;
        if (k & 1)
        {
            cout << "-1\n";
            continue;
        }
        int ptr = 61;
        vector<int> ans;
        int sum = 0;
        while (k)
        {
            if (k & (1LL << ptr))
            {
                k ^= 1LL << ptr;
                if (ptr > 1)
                {
                    ans.push_back(ptr - 2);
                    ans.push_back(0);
                    sum += 2 + ptr - 2;
                }
                else
                {
                    sum++;
                    ans.push_back(0);
                }

            }
            ptr--;
        }
        cout << sum << "\n";
        for (int x : ans)
        {
            cout << "1 ";
            for (int i = 0; i < x; i++)
            {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
    return 0;
}