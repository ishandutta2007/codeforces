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

vector< pair<int, string> > s;

int main()
{
    int n, k;
    cin >> n >> k;
    s.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].second;
        s[i].first = s[i].second.size();
    }
    string t;
    cin >> t;
    sort(s.begin(), s.end());
    int m1 = 0, m2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].first < t.size())
            m1++;
        if (s[i].first <= t.size() && s[i].second != t)
            m2++;
    }
    cout << m1 + 1 + m1 / k * 5 << " " << m2 + 1 + m2 / k * 5;
}