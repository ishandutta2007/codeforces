#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
const int MAXM = 1E4;
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }
        if ((int) s.size() > k)
            cout << -1 << "\n";
        else
        {
            vector<int> v;
            for (int x : s)
                v.push_back(x);
            while ((int) v.size() < k)
                v.push_back(v.back());
            int mod = (int) v.size();
            cout << MAXM << "\n";
            for (int i = 0; i < MAXM; i++)
            {
                cout << v[i % mod] << " \n"[i == MAXM - 1];
            }
        }
    }
    return 0;
}