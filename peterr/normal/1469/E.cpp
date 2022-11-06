#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E6;
bool add[MAXN];

int parse(string &s, int l, int r)
{
    int ans = 0;
    for (int i = l; i <= r; i++)
    {
        ans <<= 1;
        if (s[i] == '0')
            ans++;
    }
    return ans;
}

int solve(string s, int k)
{
    int n = (int) s.length();
    set<int> forbidden;
    for (int i = 0; i + k - 1 < n; i++)
    {
        if (!add[i])
            continue;
        forbidden.insert(parse(s, i, i + k - 1));
    }
    if ((int) forbidden.size() == (1 << k))
    {
        return -1;
    }
    int ans = 0;
    while (forbidden.count(ans))
        ans++;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int ans = 0;
        fill(add, add + n, true);
        if (k <= 20)
            ans = solve(s, k);
        else
        {
            int sum = 0;
            int offset = k - 20;
            for (int i = 0; i < offset; i++)
            {
                sum += s[i] == '1';
            }
            for (int i = 0; i < n - offset - 19; i++)
            {
                if (sum != offset)
                    add[i] = false;
                //cout << "sum " << i << " " << sum << endl;
                //cout << "add " << i << " " << add[i] << endl;
                if (i + 1 < n - offset - 19)
                {
                    sum += s[i + offset] == '1';
                    sum -= s[i] == '1';
                }
            }
            ans = solve(s.substr(k - 20), 20);
        }
        if (ans == -1)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            for (int i = 0; i < k - 20; i++)
                cout << "0";
            k = min(k, 20);
            for (int i = 0; i < k; i++)
            {
                if (ans & (1 << (k - i - 1)))
                    cout << "1";
                else
                    cout << "0";
            }
            cout << "\n";
        }
    }
    return 0;
}