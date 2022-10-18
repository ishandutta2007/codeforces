#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <memory.h>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>

using namespace std;

//typedef long long ll;

const int N = 100001;

int a[N], cnt[N], l[N], r[N], ans[N];

vector<pair<pair<int, int>, int> > q;

int ll = 0, rr = -1;
int curans = 0;

void addLeft()
{
    ll--;
    if (a[ll] >= N)
        return;
    if (cnt[a[ll]] == a[ll])
        curans--;
    cnt[a[ll]]++;
    if (cnt[a[ll]] == a[ll])
        curans++;
}

void removeLeft()
{
    if (a[ll] >= N)
    {
        ll++;
        return;
    }
    if (cnt[a[ll]] == a[ll])
        curans--;
    if (cnt[a[ll]] - 1 == a[ll])
        curans++;
    cnt[a[ll]]--;
    ll++;
}

void addRight()
{
    rr++;
    if (a[rr] >= N)
        return;
    if (cnt[a[rr]] == a[rr])
        curans--;
    cnt[a[rr]]++;
    if (cnt[a[rr]] == a[rr])
        curans++;
}

void removeRight()
{
    if (a[rr] >= N)
    {
        rr--;
        return;
    }
    if (cnt[a[rr]] == a[rr])
        curans--;
    if (cnt[a[rr]] - 1 == a[rr])
        curans++;
    cnt[a[rr]]--;
    rr--;
}


int main()
{
  //  freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int T = max(1, (int)sqrt(n));
    for (int i = 0; i < m; i++)
    {
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
        q.push_back({{l[i] / T, r[i]}, i});
    }
    sort(q.begin(), q.end());
    for (int i = 0; i < m; i++)
    {
        int le = l[q[i].second], re = r[q[i].second];
        while (ll > le)
            addLeft();
        while (rr < re)
            addRight();
        while (ll < le)
            removeLeft();
        while (rr > re)
            removeRight();
        ans[q[i].second] = curans;
    }
    for (int i = 0; i < m; i++)
        cout << ans[i] << "\n";
    return 0;
}