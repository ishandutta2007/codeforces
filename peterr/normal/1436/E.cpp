#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN];
int pref[MAXN];
int suf[MAXN];
int freq[MAXN + 1];
int seen[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int cur = 1;
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
        while (cur <= n && freq[cur])
            cur++;
        pref[i] = cur;
    }
    cur = 1;
    fill(freq, freq + n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        freq[a[i]]++;
        while (cur <= n && freq[cur])
            cur++;
        suf[i] = cur;
    }
    fill(seen, seen + n + 1, -1);
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        seen[a[i]] = i;
        if (i < n - 1)
        {
            if (seen[a[i + 1]] != -1 && a[i] != a[i + 1])
            {
                int l = seen[a[i + 1]] + 1;
                int mex = 1;
                while (mex <= n && seen[mex] >= l)
                    mex++;
                v.push_back(mex);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        v.push_back(pref[i]);
        v.push_back(suf[i]);
    }
    sort(v.begin(), v.end());
    int ans = 1;
    for (int x : v)
    {
        if (x == ans)
            ans++;
    }
    cout << ans << "\n";
    return 0;
}