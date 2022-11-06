#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main()
{
    int n, k;
    cin >> n >> k;
    int h = 0;
    int nodes = 1;
    uniform_int_distribution<int> dist(1, n);
    while (nodes < n)
    {
        h++;
        int add = 1;
        for (int i = 0; i < h; i++)
            add *= k;
        nodes += add;
    }
    vector<int> cand;
    while (1)
    {
        int a = dist(rng);
        int b = dist(rng);
        cand.push_back(a);
        cand.push_back(b);
        for (int i = 1; i <= n; i++)
        {
            if (i == a || i == b)
                continue;
            cout << "? " << a << " " << i << " " << b << endl;
            string q;
            cin >> q;
            if (q == "Yes")
                cand.push_back(i);
        }
        if ((int) cand.size() == 2 * (h + 1) - 1)
            break;
        cand.clear();
    }
    int ans = -1;
    for (int x : cand)
    {
        if (x == cand[0] || x == cand[1])
            continue;
        int cnt = 0;
        for (int i = 0; i < (int) cand.size(); i++)
        {
            if (cand[i] == x)
                continue;
            for (int j = i + 1; j < (int) cand.size(); j++)
            {
                if (cand[j] == x)
                    continue;
                cout << "? " << cand[i] << " " << x << " " << cand[j] << endl;
                string q;
                cin >> q;
                if (q == "Yes")
                    cnt++;
            }
        }
        if (cnt == h * h)
        {
            ans = x;
            break;
        }
    }
    cout << "! " << ans << endl;
    return 0;
}