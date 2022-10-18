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

vector< pair<int, int > > p;
vector<int> ans;

int main()
{
    long long a, b;
    cin >> a >> b;
    queue< pair<long long, pair<int, int> > > q;
    q.push({a, {0, -1}});
    p.push_back({a, -1});
    while (!q.empty())
    {
        long long v = q.front().first;
        int num = q.front().second.first;
        int pr = q.front().second.second;
        if (v == b)
        {
            ans.push_back(b);
            while (p[num].first != a)
            {
                num = p[num].second;
                ans.push_back(p[num].first);
            }
            cout << "YES" << endl << ans.size() << endl;
            for (int i = ans.size() - 1; i >= 0; i--)
                cout << ans[i] << " ";
            return 0;
        }
        q.pop();
        if (v * 2 <= b)
        {
            q.push({2 * v,  {p.size(), num}});
            p.push_back({2 * v, num});
        }
        if (10 * v + 1 <= b)
        {
            q.push({10 * v + 1,  {p.size(), num}});
            p.push_back({10 * v + 1, num});
        }
    }
    cout << "NO";
    return 0;
}