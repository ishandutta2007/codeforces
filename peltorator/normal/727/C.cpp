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
    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 1; i + 2 <= n; i += 3)
    {
        int k, l, m;
        cout << "? " << i << " " << i + 1 << endl;
        fflush(stdout);
        cin >> k;
        cout << "? " << i + 1 << " " << i + 2 << endl;
        fflush(stdout);
        cin >> l;
        cout << "? " << i << " " << i + 2 << endl;
        fflush(stdout);
        cin >> m;
        ans.push_back((k + m - l) / 2);
        ans.push_back((k + l - m) / 2);
        ans.push_back((m + l - k) / 2);
    }
    for (int i = n - (n % 3) + 1; i <= n; i++)
    {
        cout << "? " << 1 << " " << i << endl;
        fflush(stdout);
        int k;
        cin >> k;
        ans.push_back(k - ans[0]);
    }
    cout << "!";
    for (int i = 0; i < ans.size(); i++)
        cout << " " << ans[i];
    cout << endl;
    fflush(stdout);
    return 0;
}