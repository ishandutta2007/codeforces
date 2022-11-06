#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN + 1];

int getNxt(set<int> &s, int num)
{
    if (s.empty())
        return -1;
    auto it = s.upper_bound(num);
    if (it == s.end())
        return *s.begin();
    else
        return *it;
}

int getPrev(set<int> &s, int num)
{
    if (s.empty())
        return -1;
    auto it = s.lower_bound(num);
    if (it == s.begin())
        return *(--s.end());
    else
        return *(--it);
}

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
        set<int> living;
        set<int> ready;
        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            living.insert(i);
            cin >> a[i];
            if (i > 1 && __gcd(a[i], a[i - 1]) == 1)
                ready.insert(i);
        }
        if (n == 1)
        {
            if (a[1] == 1)
                cout << "1 1\n";
            else
                cout << "0\n";
            continue;
        }
        if (__gcd(a[1], a[n]) == 1)
            ready.insert(1);
        int cur = 1;
        while (ready.size())
        {
            int nxt = getNxt(ready, cur);
            ans.push_back(nxt);
            ready.erase(ready.find(nxt));
            living.erase(living.find(nxt));
            if (living.empty())
                break;
            cur = getNxt(living, nxt);
            int prev = getPrev(living, cur);
            if (__gcd(a[cur], a[prev]) == 1)
                ready.insert(cur);
            else if (ready.count(cur))
                ready.erase(ready.find(cur));
        }
        cout << ans.size() << " ";
        for (int x : ans)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}