#include <bits/stdc++.h>
#define f(i, a, b) for(int i = a; i < b; i++)

using namespace std;

const int MAXN = 300000;
int sticks[MAXN];

int main()
{
    int n;
    cin >> n;
    f(i, 0, n)
        cin >> sticks[i];
    bool odd = true;
    int i = n - 1;
    int j = n - 1;
    long long ans = 0;
    while (i >= 0)
    {
        while (sticks[i] >= 2)
        {
            sticks[i] -= 2;
            while (odd && sticks[j] % 2 == 0)
            {
                j--;
                if (j < 0)
                {
                    j = 0;
                    odd = false;
                }
            }
            while (!odd && j <= i && sticks[j] == 0)
            {
                j++;
            }
            if (j == i)
            {
                if (odd)
                {
                    ans++;
                    sticks[j]--;
                }
                else
                {
                    sticks[i] += 2;
                    ans += sticks[i] / 3;
                    sticks[i] %= 3;
                }

            }
            else if (j < i)
            {
                if (odd)
                {
                    ans++;
                    sticks[j]--;
                }
                else
                {
                    sticks[i] += 2;
                    int pairs = sticks[i] / 2;
                    ans += min(sticks[j], pairs);
                    sticks[i] -= min(sticks[j], pairs) * 2;
                    sticks[j] = max(0, sticks[j] - pairs);
                }
            }
        }
        i--;
        j = min(i, j);
    }
    cout << ans;
    return 0;
}