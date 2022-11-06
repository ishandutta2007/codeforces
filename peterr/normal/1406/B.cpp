#include <bits/stdc++.h>

using namespace std;

const long long NEG = -1E18;

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
        long long ans = NEG;
        vector<int> pos;
        vector<int> neg;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (!x)
                ans = 0;
            if (x > 0)
                pos.push_back(x);
            else
                neg.push_back(-x);
        }
        sort(pos.rbegin(), pos.rend());
        sort(neg.rbegin(), neg.rend());
        for (int i = 0; i <= 5; i += 2)
        {
            if ((int) neg.size() < i || (int) pos.size() < 5 - i)
                continue;
            long long temp = 1;
            for (int j = 0; j < i; j++)
                temp *= neg[j];
            for (int j = 0; j < 5 - i; j++)
                temp *= pos[j];
            ans = max(ans, temp);
        }
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        for (int i = 1; i <= 5; i += 2)
        {
            if ((int) neg.size() < i || (int) pos.size() < 5 - i)
                continue;
            long long temp = -1;
            for (int j = 0; j < i; j++)
                temp *= neg[j];
            for (int j = 0; j < 5 - i; j++)
                temp *= pos[j];
            ans = max(ans, temp);
        }
        cout << ans << "\n";
    }
    return 0;
}