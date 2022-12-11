#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s11;
    string s22;
    cin >> s11;
    cin >> s22;
    int k = 0;
    int ind = s11.size() - 1;
    for (int i = 0; i < s11.size(); ++i)
    {
        if (s11[i] != '0')
        {
            ind = i;
            break;
        }
    }
    int ind2 = s22.size() - 1;
    for (int i = 0; i < s22.size(); ++i)
    {
        if (s22[i] != '0')
        {
            ind2 = i;
            break;
        }
    }
    string s1 = "";
    string s2 = "";
    for (int i = ind; i < s11.size(); ++i)
    {
        s1 += s11[i];
    }
    for (int i = ind2; i < s22.size(); ++i)
    {
        s2 += s22[i];
    }
    if (s1.size() < s2.size())
    {
        k = -1;
    }
    if (s1.size() > s2.size())
    {
        k = 1;
    }
    if (k == 0)
    {
        for (int i = 0; i < s1.size(); ++i)
        {
            if (s1[i] < s2[i])
            {
                k = -1;
                break;
            }
            if (s1[i] > s2[i])
            {
                k = 1;
                break;
            }
        }
    }
    if (k == 0)
    {
        cout << "=" << endl;
    }
    if (k == 1)
    {
        cout << ">" << endl;
    }
    if (k == -1)
    {
        cout << "<" << endl;
    }
    return 0;
}