#include <bits/stdc++.h>

using namespace std;

const int MAXB = 20;
int freq[MAXB];
const int MAXN = 2E5;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int j = 0; j < MAXB; j++)
        {
            if (x & (1 << j))
                freq[j]++;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int i = 0; i < MAXB; i++)
        {
            if (freq[i])
            {
                freq[i]--;
                temp += 1 << i;
            }
        }
        ans += (long long) temp * temp;
    }
    cout << ans << "\n";
    return 0;
}