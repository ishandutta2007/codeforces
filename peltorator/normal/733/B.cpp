#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <tuple>
#include <iostream>
#include <cstdio>

using namespace std;

vector<int> l, r;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    l.resize(n);
    r.resize(n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
        ans += l[i] - r[i];
    }
    int answ = abs(ans);
    int num = 0;
    for (int i = 0; i < n; i++)
            if (abs(ans - 2 * l[i] + 2 * r[i]) > answ)
            {
                answ = abs(ans - 2 * l[i] + 2 * r[i]);
                num = i + 1;
            }
    cout << num;
    return 0;
}