#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;
tuple<int, int, int, int> a[MAXN + 1];
int par[MAXN + 1];
int sz[MAXN + 1];
int col[MAXN + 1];
bool bad[MAXN + 1];

int getRoot(int x)
{
    if (par[x] != x)
        par[x] = getRoot(par[x]);
    return par[x];
}

bool mge(int x, int y)
{
    x = getRoot(x);
    y = getRoot(y);
    if (x == y)
        return false;
    if (sz[x] > sz[y])
        swap(x, y);
    par[x] = y;
    sz[y] += sz[x];
    return true;
}

bool isUpper(int x, int y)
{
    return y == 0 ? x > 0 : y > 0;
}

int getNxt(int ind, int n)
{
    ind++;
    if (ind > n)
        return 1;
    return ind;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    fill(sz + 1, sz + n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        int x, y, v;
        cin >> x >> y >> v;
        a[i] = {x, y, v, i};
    }
    int numColors = 0;
    for (int i = 1; i <= n; i++)
    {
        if (col[i])
            continue;
        col[i] = ++numColors;
        int temp = get<2>(a[i]);
        bad[i] = temp == i;
        while (temp != i)
        {
            mge(temp, i);
            col[temp] = numColors;
            temp = get<2>(a[temp]);
        }
    }
    if (*min_element(bad + 1, bad + n + 1) == 1)
    {
        cout << "0\n";
        return 0;
    }
    vector<pair<int, int>> ans;
    int x0 = 0;
    int y0 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (bad[i])
            continue;
        x0 = get<0>(a[i]);
        y0 = get<1>(a[i]);
        break;
    }
    sort(a + 1, a + n + 1, [&] (tuple<int, int, int, int> tup1, tuple<int, int, int, int> tup2) {
         int x1 = get<0>(tup1);
         int y1 = get<1>(tup1);
         int x2 = get<0>(tup2);
         int y2 = get<1>(tup2);
         int dx1 = x1 - x0;
         int dy1 = y1 - y0;
         int dx2 = x2 - x0;
         int dy2 = y2 - y0;
         if (dx1 == 0 && dy1 == 0)
            return true;
         if (dx2 == 0 && dy2 == 0)
            return false;
         bool upper1 = isUpper(dx1, dy1);
         bool upper2 = isUpper(dx2, dy2);
         if (upper1 == upper2)
         {
            long long cross = (long long) dx1 * dy2 - (long long) dy1 * dx2;
            return cross > 0;
         }
         return upper1;
    });
    vector<tuple<int, int, int, int>> pts;
    for (int i = 2; i <= n; i++)
    {
        int ind = get<3>(a[i]);
        if (bad[ind])
            continue;
        pts.push_back(a[i]);
    }
    int start = 0;
    int m = (int) pts.size();
    while (1)
    {
        bool good = true;
        for (int i = 0; i < m - 1; i++)
        {
            int dx1 = get<0>(pts[(start + i) % m]) - x0;
            int dy1 = get<1>(pts[(start + i) % m]) - y0;
            int dx2 = get<0>(pts[(start + i + 1) % m]) - x0;
            int dy2 = get<1>(pts[(start + i + 1) % m]) - y0;
            long long cross = (long long) dx1 * dy2 - (long long) dy1 * dx2;
            if (cross < 0)
                good = false;
        }
        if (good)
            break;
        start++;
    }
    //cout << "start " << start << endl;
    for (int i = 0; i < m - 1; i++)
    {
        int ind1 = get<3>(pts[(start + i) % m]);
        int ind2 = get<3>(pts[(start + i + 1) % m]);
        if (mge(ind1, ind2))
        {
            ans.push_back({ind1, ind2});
            swap(get<2>(pts[(start + i) % m]), get<2>(pts[(start + i + 1 ) % m]));
        }
    }
    while (get<2>(a[1]) != get<3>(a[1]))
    {
        int label = get<2>(a[1]);
        int j = 0;
        while (get<3>(pts[j]) != label)
            j++;
        ans.push_back({get<3>(a[1]), get<3>(pts[j])});
        swap(get<2>(a[1]), get<2>(pts[j]));
    }
    cout << ans.size() << "\n";
    for (pair<int, int> pr : ans)
        cout << pr.first << " " << pr.second << "\n";
    return 0;
}