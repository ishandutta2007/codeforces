#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN + 1];
long long pref[MAXN + 1];

void precompute(int l, int r, set<int> &seen, int n)
{
    if (l > r)
        return;
    //cout << "pref " << pref[r] - pref[l - 1] << endl;
    if (pref[r] - pref[l - 1] <= 1000000000)
        seen.insert((int) (pref[r] - pref[l - 1]));
    int mn = a[l];
    int mx = a[r];
    int mid = (mn + mx) / 2;
    int ind = l;
    for (int jump = n; jump; jump >>= 1)
    {
        while (ind + jump <= n && a[ind + jump] <= mid)
            ind += jump;
    }
    if (ind != r)
        precompute(l, ind, seen, n);
    if (ind + 1 != l)
        precompute(ind + 1, r, seen, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] + a[i];
        }
        set<int> seen;
        precompute(1, n, seen, n);
        while (q--)
        {
            int s;
            cin >> s;
            bool ans = seen.count(s);
            if (ans)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}