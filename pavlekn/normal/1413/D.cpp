#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a;
    vector<int> q;
    int cnt = 0;
    for (int i = 0; i < 2 * n; ++i)
    {
        char c;
        cin >> c;
        if (c == '+')
        {
            ++cnt;
            q.push_back(0);
        }
        else
        {
            --cnt;
            if (cnt < 0)
            {
                cout << "NO" << endl;
                return 0;
            }
            int num;
            cin >> num;
            q.push_back(num);
            a.push_back(num);
        }
    }
    set<int> s;
    vector<int> ans;
    for (int i = 2 * n - 1; i >= 0; --i)
    {
        if (q[i] == 0)
        {
            ans.push_back(*s.begin());
            s.erase(s.begin());
        }
        else
        {
            s.insert(q[i]);
        }
    }
    set<int> r;
    int ind = n - 1;
    for (int i = 0; i < 2 * n; ++i)
    {
        if (q[i] == 0)
        {
            r.insert(ans[ind--]);
        }
        else
        {
            if ((*r.begin()) != q[i])
            {
                cout << "NO" << endl;
                return 0;
            }
            r.erase(r.begin());
        }
    }
    cout << "YES" << endl;
    for (int i = n - 1; i >= 0; --i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}