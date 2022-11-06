#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];
int ans[MAXN];
int ans2[MAXN];

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
        set<int> nums;
        set<int> nums2;
        for (int i = 1; i <= n; i++)
        {
            nums.insert(i);
            nums2.insert(i);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            nums.erase(a[i]);
            nums2.erase(a[i]);
        }
        int pos = 0;
        while (pos < n)
        {
            int cur = a[pos];
            ans[pos] = a[pos];
            ans2[pos] = a[pos];
            pos++;
            while (pos < n && a[pos] == a[pos - 1])
            {
                auto it = --nums.lower_bound(cur);
                int nxt = *it;
                ans[pos] = nxt;
                nums.erase(it);
                ans2[pos] = *nums2.begin();
                nums2.erase(nums2.begin());
                pos++;
            }
        }
        for (int i = 0; i < n; i++)
            cout << ans2[i] << " \n"[i == n - 1];
        for (int i = 0; i < n; i++)
            cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;
}