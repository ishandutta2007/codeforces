#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
int a[MAXN];

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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long ans = 0;
        set<int> pos;
        set<int> neg;
        for (int i = 1; i < n - 1; i++)
        {
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
            {
                pos.insert(i);
                ans += a[i];
            }
            else if (a[i] < a[i - 1] && a[i] < a[i + 1])
            {
                neg.insert(i);
                ans -= a[i];
            }
        }
        if (n == 1 || a[0] > a[1])
        {
            pos.insert(0);
            ans += a[0];
        }
        if (n > 1 && a[n - 1] > a[n - 2])
        {
            pos.insert(n - 1);
            ans += a[n - 1];
        }
        cout << ans << "\n";
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            if (l != r)
            {
                if (pos.count(l))
                {
                    pos.erase(l);
                    ans -= a[l];
                }
                if (pos.count(r))
                {
                    pos.erase(r);
                    ans -= a[r];
                }
                if (neg.count(l))
                {
                    neg.erase(l);
                    ans += a[l];
                }
                if (neg.count(r))
                {
                    neg.erase(r);
                    ans += a[r];
                }
                swap(a[l], a[r]);
                for (int i = l; i <= r; i += r - l)
                {
                    for (int j = -1; j <= 1; j++)
                    {
                        int ind = i + j;
                        if (ind < 0 || ind >= n)
                            continue;
                        if (pos.count(ind))
                        {
                            pos.erase(ind);
                            ans -= a[ind];
                        }
                        else if (neg.count(ind))
                        {
                            neg.erase(ind);
                            ans += a[ind];
                        }
                        if (a[ind] >= a[max(ind - 1, 0)] && a[ind] >= a[min(ind + 1, n - 1)])
                        {
                            pos.insert(ind);
                            ans += a[ind];
                        }
                        if (a[ind] <= a[max(ind - 1, 0)] && a[ind] <= a[min(ind + 1, n - 1)])
                        {
                            neg.insert(ind);
                            ans -= a[ind];
                        }
                    }
                }
            }
            if (!neg.empty())
            {
                int negmax = *neg.rbegin();
                int posmax = *pos.rbegin();
                long long temp = ans;
                if (negmax > posmax)
                {
                    temp += a[negmax];
                }
                if (1)
                {
                    int negmin = *neg.begin();
                    int posmin = *pos.begin();
                    if (negmin < posmin)
                    {
                        temp += a[negmin];
                    }
                }
                cout << temp << "\n";
            }
            else
                cout << ans << "\n";
/*
            cout << "pos\n";
            for (auto x : pos)
                cout << x << " ";
            cout << "\n";
            cout << "neg\n";
            for (auto x : neg)
                cout << x << " ";
            cout << "\n";
*/
        }
    }
    return 0;
}