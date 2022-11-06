#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int boxes[MAXN];

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    vector<int> pos;
    for (int i = 0; i < n; i++)
    {
        cin >> boxes[i];
        sum += boxes[i];
        if (boxes[i])
        {
            pos.push_back(i);
        }
    }
    long long ans = 1E18;
    int d = -1;
    for (int j = 2; j <= sum; j++)
    {
        if (sum % j == 0)
        {
            d = j;
            long long cnt = 0;
            for (int i = 0; i < (int) pos.size(); i += d)
            {
                int x = pos[i + d / 2];
                for (int j = i; j < i + d; j++)
                {
                    cnt += abs(x - pos[j]);
                }
            }
            ans = min(ans, cnt);

        }
    }
    if (ans == 1E18)
     cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}