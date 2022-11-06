#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
int p[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        int two = 1;
        while (two * 2 <= n)
            two *= 2;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            p[i] = i / 2;
            sum += 31 - __builtin_clz(i);
        }
        int orig = two;
        int cur = two + 1;
        int numTwos = 1;
        if (cur > n)
        {
            two /= 2;
            cur = two + 1;
            numTwos++;
        }
        vector<int> chain;
        while (sum < d && two != 1)
        {
            int diff = d - sum;
            if (numTwos + (int) chain.size() <= diff)
            {
                sum += numTwos + (int) chain.size();
                if (!chain.empty())
                    p[cur] = chain[(int) chain.size() - 1];
                else
                    p[cur] = orig;
                chain.push_back(cur);
            }
            else
            {
                int parent = two;
                diff--;
                while (diff && parent * 2 <= n)
                {
                    parent *= 2;
                    diff--;
                }
                int ind = 0;
                while (diff)
                {
                    parent = chain[ind];
                    ind++;
                    diff--;
                }
                p[cur] = parent;
                sum = d;
            }
            cur++;
            if (__builtin_popcount(cur) == 1 || cur > n)
            {
                two /= 2;
                cur = two + 1;
                numTwos++;
            }
        }
        if (sum != d)
        {
            cout << "NO" << "\n";
        }
        else
        {
            cout << "YES" << "\n";
            for (int i = 2; i <= n; i++)
            {
                if (i > 2)
                    cout << " ";
                cout << p[i];
            }
            cout << "\n";
        }
    }
    return 0;
}