// Not my code https://codeforces.com/contest/1608/submission/138766965

// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, ans;
struct node
{
    int x, y, c, d;
} a[100005];
bool solve1(int lim)
{
    int l = 0, c = 0;
    while (l != n && c != lim)
    {
        if (a[l].c == 0)
            ++c;
        ++l;
    }
    while (l && l != n && a[l].x == a[l - 1].x)
        ++l;
    if (c != lim)
        return false;
    std::vector<node> t(a + l, a + n);
    std::sort(t.begin(), t.end(), [&](const node &A, const node &B)
              { return A.y < B.y; });
    l = 0;
    c = 0;
    while (l != t.size() && c != lim)
    {
        if (t[l].c == 1)
            ++c;
        ++l;
    }
    while (l && l != t.size() && t[l].y == t[l - 1].y)
        ++l;
    if (c != lim)
        return false;
    c = 0;
    while (l != t.size())
    {
        if (t[l].c == 2)
            ++c;
        ++l;
    }
    return c >= lim;
}
bool solve2(int lim)
{
    int l = 0, c = 0;
    while (l != n && c != lim)
    {
        if (a[l].c == 0)
            ++c;
        ++l;
    }
    while (l && l != n && a[l].x == a[l - 1].x)
        ++l;
    if (c != lim)
        return false;
    c = 0;
    while (l != n && c != lim)
    {
        if (a[l].c == 1)
            ++c;
        ++l;
    }
    while (l && l != n && a[l].x == a[l - 1].x)
        ++l;
    if (c != lim)
        return false;
    c = 0;
    while (l != n && c != lim)
    {
        if (a[l].c == 2)
            ++c;
        ++l;
    }
    return c == lim;
}
bool check(int x)
{
    for (int i = 0; i != 4; ++i)
    {
        for (int j = 0; j != n; ++j)
            std::swap(a[j].x, a[j].y), a[j].x *= -1;
        std::sort(a, a + n, [&](const node &A, const node &B)
                  { return A.x < B.x; });
        int p[3] = {0, 1, 2};
        do
        {
            for (int k = 0; k != n; ++k)
                a[k].c = p[a[k].d];
            if (solve1(x) || solve2(x))
                return true;
        } while (std::next_permutation(p, p + 3));
    }
    return false;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> a[i].x >> a[i].y >> a[i].d, --a[i].d;
    int l = 1, r = n / 3;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    std::cout << l * 3 << std::endl;
    return 0;
}