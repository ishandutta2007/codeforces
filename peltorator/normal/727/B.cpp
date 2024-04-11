#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <limits>
#include <tuple>
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long ans = 0;
    string s;
    cin >> s;
    s += 'a';
    long long cur = 0, f = -1000;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '.')
            f = i;
        else if (s[i] >= '0' && s[i] <= '9')
            cur = cur * 10 + (s[i] - '0');
        else
        {
            if (f != i - 3)
                cur *= 100;
            ans += cur;
            cur = 0;
            f = -1000;
        }
    }
    if (ans == 0)
    {
        cout << 0;
        return 0;
    }
    vector<int> a;
    while (ans > 0)
    {
        a.push_back(ans % 10);
        ans /= 10;
    }
    if (a.size() < 3)
    {
        cout << "0.";
        if (a.size() == 1)
            cout << "0" << a[0];
        else
            cout << a[1] << a[0];
        return 0;
    }
    bool ok = false;
    for (int i = 0; i < (a.size() - 2) % 3; i++)
    {
        cout << a[a.size() - 1 - i];
       ok = true;
    }
    if ((a.size() - 2) % 3 != a.size())
    {
        for (int i = a.size() - (a.size() - 2) % 3 - 1; i >= 2; i-=3)
        {
            if (ok || i != a.size() - (a.size() - 2) % 3 - 1)
                cout << ".";
            cout << a[i] << a[i - 1] << a[i - 2];
        }
        if (a[0] != 0 || a[1] != 0)
            cout << "." << a[1] << a[0];
    }
    return 0;
}