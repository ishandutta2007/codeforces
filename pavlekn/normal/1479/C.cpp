#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); srand(clock());
    int L, R;
    cin >> L >> R;
    vector<int> u;
    vector<int> v;
    vector<int> w;
    for (int i = 1; i < 21; ++i)
    {
        u.push_back(i);
        v.push_back(0);
        w.push_back(1);
        int cur = 1;
        for (int j = 1; j < i; ++j)
        {
            u.push_back(i);
            v.push_back(j);
            w.push_back(cur);
            cur *= 2;
        }
    }
    R -= L;
    for (int i = 0; i < 20; ++i)
    {
        if (R & (1 << i))
        {
            u.push_back(21);
            v.push_back(i + 1);
            w.push_back(R - (1 << i) + L);
            R -= (1 << i);
        }
    }
    u.push_back(21);
    v.push_back(0);
    w.push_back(L);
    cout << "YES" << endl;
    cout << 22 << " " << u.size() << endl;
    for (int i = 0; i < u.size(); ++i)
    {
        cout << 22 - u[i] << " " << 22 - v[i] << " " << w[i] << endl;
    }
    return 0;
}