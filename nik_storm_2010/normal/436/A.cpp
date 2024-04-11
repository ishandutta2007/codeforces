#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>
#include <fstream>
#include <stack>
#include <deque>
#include <utility>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

vector <pii> a, b;
priority_queue <int> aa, bb;
int la, lb;

void update(int x)
{
    while (la < a.size() && a[la].first <= x) aa.push(a[la].second), la++;
    while (lb < b.size() && b[lb].first <= x) bb.push(b[lb].second), lb++;
}

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++)
    {
        int t, h, m;
        scanf("%d %d %d", &t, &h, &m);
        if (t == 0) a.push_back(make_pair(h, m)); else b.push_back(make_pair(h, m));
    }
    int type, h;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    while (!aa.empty()) aa.pop();
    while (!bb.empty()) bb.pop();
    la = 0, lb = 0, type = 0, h = x;
    int ans1 = 0;
    update(h);
    while (true)
    {
        if (type == 0 && aa.empty()) break;
        if (type == 1 && bb.empty()) break;
        int p;
        if (type == 0)
        {
            h += aa.top();
            aa.pop();
        }
        else
        {
            h += bb.top();
            bb.pop();
        }
        type = 1 - type;
        ans1++;
        update(h);
    }
    while (!aa.empty()) aa.pop();
    while (!bb.empty()) bb.pop();
    la = 0, lb = 0, type = 1, h = x;
    int ans2 = 0;
    update(h);
    while (true)
    {
        if (type == 0 && aa.empty()) break;
        if (type == 1 && bb.empty()) break;
        int p;
        if (type == 0)
        {
            h += aa.top();
            aa.pop();
        }
        else
        {
            h += bb.top();
            bb.pop();
        }
        type = 1 - type;
        ans2++;
        update(h);
    }
    printf("%d\n", max(ans1, ans2));
    return 0;
}