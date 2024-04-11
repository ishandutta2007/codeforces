#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;

vector<string> s, t;

int main()
{
    int n, m;
    cin >> n >> m;
    s.resize(n);
    t.resize(m);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < m; i++)
        cin >> t[i];
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    int x = 0;
    int i = 0, j = 0;
    while (i < s.size() && j < t.size())
    {
        if (s[i] == t[j])
        {
            x++;
            i++;
            j++;
        }
        else if (s[i] < t[j])
            i++;
        else
            j++;
    }
    int t1 = s.size() - x, t2 = t.size() - x;
    t1 += (x + 1) / 2;
    t2 += x / 2;
    if (t1 >= t2 + 1)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}