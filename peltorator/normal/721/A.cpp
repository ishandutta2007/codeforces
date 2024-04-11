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

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += 'W';
    vector<int> ans;
    int cur = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'B')
            cur++;
        else
        {
            if(cur > 0)
                ans.push_back(cur);
            cur = 0;
        }
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << " ";
}