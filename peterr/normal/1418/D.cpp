#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    int mx = 0;
    int mn = 1E9;
    set<int> s;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        mx = max(mx, x);
        mn = min(mn, x);
        s.insert(x);
    }
    sort(v.begin(), v.end());
    multiset<int> gaps;
    for (int i = 1; i < (int) v.size(); i++)
    {
        gaps.insert(v[i] - v[i - 1]);
    }
    q++;
    while (q--)
    {
        int ans = 0;
        if (!gaps.empty())
        {
            ans = mx - mn - *gaps.rbegin();
        }
        cout << ans << "\n";
        if (q == 0)
            break;
        int t, x;
        cin >> t >> x;
        if (t == 0)
        {
            if ((int) s.size() >= 2)
            {
                if (x == mx)
                {
                    s.erase(x);
                    gaps.erase(gaps.find(x - *s.rbegin()));
                }
                else if (x == mn)
                {
                    s.erase(x);
                    gaps.erase(gaps.find(*s.begin() - x));
                }
                else
                {
                    auto it = s.find(x);
                    auto nxt = it;
                    auto prev = it;
                    nxt++;
                    prev--;
                    gaps.erase(gaps.find(*nxt - x));
                    gaps.erase(gaps.find(x - *prev));
                    gaps.insert(*nxt - *prev);
                    s.erase(x);
                }
            }
            s.erase(x);
            if (!s.empty())
            {
                mn = *s.begin();
                mx = *s.rbegin();
            }
        }
        else
        {
            if (s.empty())
            {
                mx = mn = x;
            }
            else
            {
                if (x > mx)
                {
                    gaps.insert(x - mx);
                    mx = x;
                }
                else if (x < mn)
                {
                    gaps.insert(mn - x);
                    mn = x;
                }
                else
                {
                    auto it = s.insert(x).first;
                    auto nxt = it;
                    auto prev = it;
                    nxt++;
                    prev--;
                    gaps.erase(gaps.find(*nxt - *prev));
                    gaps.insert(*nxt - x);
                    gaps.insert(x - *prev);
                }
            }
            s.insert(x);
        }
    }
    return 0;
}