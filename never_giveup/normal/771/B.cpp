#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    vector <string> w;
    for (char c = 'A'; c <= 'Z'; c++)
    {
        for (char d = 'a'; d <= 'z'; d++)
        {
            string s = "";
            s += c;
            s += d;
            w.push_back(s);
        }
    }
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector <string> a;
    vector <string> ans(n);
    int sz = n - k + 1;
    for (int i = 0; i < n - k + 1; i++)
    {
        string s;
        cin >> s;
        a.push_back(s);
    }
    if (a[0] == "YES")
    {
        vector <string> kek;
        for (int i = 0; i < k; i++)
        {
            kek.push_back(w[i]);
            ans[i] = w[i];
        }
        string to_dif = ans[1];
        string to_ok = ans[0];
        int last = 0;
        for (int i = 1; i < sz; i++)
        {
            if (a[i] == "YES")
            {
                ans[i + k - 1] = to_ok;
                kek.erase(kek.begin());
                kek.push_back(to_ok);
                to_ok = kek[0];
                to_dif = kek[1];
            }
            else
            {
                ans[i + k - 1] = to_dif;
                kek.erase(kek.begin());
                kek.push_back(to_dif);
                for (auto c : w)
                {
                    bool good = 1;
                    for (auto d : kek)
                    {
                        if (d == c)
                        {
                            good = 0;
                            break;
                        }
                    }
                    if (good)
                    {
                        to_ok = c;
                        break;
                    }
                }
                to_dif = kek[1];
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return 0;
    }
    else
    {
        vector <string> kek;
        for (int i = 0; i < k; i++)
        {
            kek.push_back(w[i]);
        }
        kek.push_back(kek[1]);
        kek.erase(kek.begin());
        for (int i = 0; i < k; i++)
        {
            ans[i] = kek[i];
        }
        string to_dif = kek[1];
        string to_ok = w[0];
        int last = 0;
        for (int i = 1; i < sz; i++)
        {
            if (a[i] == "YES")
            {
                ans[i + k - 1] = to_ok;
                kek.erase(kek.begin());
                kek.push_back(to_ok);
                to_ok = kek[0];
                to_dif = kek[1];
            }
            else
            {
                ans[i + k - 1] = to_dif;
                kek.erase(kek.begin());
                kek.push_back(to_dif);
                for (auto c : w)
                {
                    bool good = 1;
                    for (auto d : kek)
                    {
                        if (d == c)
                        {
                            good = 0;
                            break;
                        }
                    }
                    if (good)
                    {
                        to_ok = c;
                        break;
                    }
                }
                to_dif = kek[1];
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return 0;
    }
}