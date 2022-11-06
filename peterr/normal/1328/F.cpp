#include <bits/stdc++.h>

using namespace std;

const long long INF = 1E18;
const int MAXN = 2E5;
int a[MAXN];
map<int, int> freq;

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (freq.count(a[i]))
            freq[a[i]]++;
        else
            freq[a[i]] = 1;
    }
    sort(a, a + n);
    int longest = 0;
    for (int i = 0; i < n; )
    {
        int cnt = 0;
        int j = i;
        while (j < n && a[i] == a[j])
        {
            cnt++;
            j++;
            longest = max(longest, cnt);
        }
        i = j;
    }
    if (longest >= k)
        cout << 0 << endl;
    else
    {
        long long ans = INF;
        int target = a[k - 1];
        long long sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += max(0, target - a[i] - 1);
        }
        ans = min(ans, sum + max(0, k - freq[target]));
        sum = 0;
        target = a[n - k];
        for (int i = 0; i < k; i++)
        {
            sum += max(0, a[n - i - 1] - target - 1);
        }
        ans = min(ans, sum + max(0, k - freq[target]));
        int ind = 0;
        target = a[ind];
        int below = freq[a[0]];
        int above = n - below;
        long long aboveCost = 0;
        for (int i = 0; i < n; i++)
        {
            aboveCost += max(0, a[i] - target - 1);
        }
        long long belowCost = 0;
        while (ind < n)
        {
            ans = min(ans, aboveCost + belowCost + max(0, (k - freq[target])));
            while (ind < n && a[ind] == target)
                ind++;
            if (ind < n)
            {
                int old = target;
                target = a[ind];
                belowCost += (long long) (below - freq[old]) * (target - old);
                belowCost += (long long) freq[old] * (target - old - 1);
                below += freq[target];
                aboveCost -= (long long) (above - freq[target]) * (target - old);
                aboveCost -= (long long) freq[target] * (target - old - 1);
                above -= freq[target];
            }
        }
        cout << ans << endl;
    }
    return 0;
}