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

vector< pair< vector<int>, int> > a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    int num = -1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        a[i].first.resize(3);
        cin >> a[i].first[0] >> a[i].first[1] >> a[i].first[2];
        a[i].second = i;
        sort(a[i].first.rbegin(), a[i].first.rend());
        if (ans < a[i].first[2])
        {
            ans = a[i].first[2];
            num = i;
        }
    }
    sort(a.begin(), a.end());
    int num1 = -1, num2 = -1;
    int ans1 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i].first[0] == a[i + 1].first[0] && a[i].first[1] == a[i + 1].first[1])
        {
            int q = min(a[i].first[1], a[i].first[2] + a[i + 1].first[2]);
            if (q > ans1)
            {
                ans1 = q;
                num1 = a[i].second;
                num2 = a[i + 1].second;
            }
        }
    }
    if (ans > ans1)
        cout << "1 " << num + 1;
    else
        cout << "2 " << num1 + 1 << " " << num2 + 1;
    return 0;
}