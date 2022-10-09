#pragma GCC optimize(3)
#include <bits/stdc++.h>

struct Root
{
    int p, c;
    long long e, x;
    std::vector<int> v;
    Root(int p, long long e) : p(p), e(e) { }
};

constexpr int MAXN = 200200;
bool oncirc[MAXN];
std::vector<std::pair<int, long long>> e[MAXN];
std::vector<Root> circ;
long long ans[MAXN];

bool mark[MAXN];

int dfs(int v, int p)
{
    if (mark[v])
    {
        return v;
    }
    else
    {
        mark[v] = true;
    }
    for (auto it = e[v].begin(); it != e[v].end(); ++it)
    {
        int w = it->first;
        if (w == p)
        {
            continue;
        }
        int t = dfs(w, v);
        if (t != -1)
        {
            circ.push_back(Root(w, it->second));
            return v == t ? -1 : t;
        }
    }
    return -1;
}

int findcirc(int n)
{
    int m;

    dfs(0, -1);
    m = circ.size();
    for (int i = 0; i < m; ++i)
    {
        oncirc[circ[i].p] = true;
    }
    return m;
}

Root* root;
long long dd[MAXN], cc[MAXN], ss[MAXN], xx[MAXN];

void gao1(int v, int p)
{
    root->v.push_back(v);
    cc[v] = 1;
    ss[v] = 0;
    for (auto it = e[v].begin(); it != e[v].end(); ++it)
    {
        int w = it->first;
        if (w == p || oncirc[w])
        {
            continue;
        }
        dd[w] = dd[v] + it->second;
        gao1(w, v);
        cc[v] += cc[w];
        ss[v] += ss[w] + cc[w] * it->second;
    }
}

void gao2(int v, int p, int n)
{
    for (auto it = e[v].begin(); it != e[v].end(); ++it)
    {
        int w = it->first;
        if (w == p || oncirc[w])
        {
            continue;
        }
        xx[w] = xx[v] + (ss[v] - (ss[w] + cc[w] * it->second)) +
                (n - cc[w]) * it->second;
        gao2(w, v, n);
    }
}

void calctree(Root& r)
{
    root = &r;
    dd[r.p] = 0;
    gao1(r.p, -1);
    xx[r.p] = 0;
    r.c = cc[r.p];
    gao2(r.p, -1, r.c);
    for (auto it = r.v.begin(); it != r.v.end(); ++it)
    {
        ans[*it] = xx[*it] + ss[*it];
    }
    r.x = ans[r.p];
}

long long ee[MAXN + MAXN];

void calccirc(int n, int m)
{
    long long circlen = 0;
    long long total = 0;
    long long cursum = 0;
    int curcnt = 0;
    int q = 0;

    for (int i = 0; i < m; ++i)
    {
        circlen += circ[i].e;
        total += circ[i].x;
        ee[i + 1 + m] = ee[i + 1] = circ[i].e;
    }
    ee[0] = 0;
    std::partial_sum(ee, ee + m + m + 1, ee);
    while (2 * (ee[q] - ee[0]) <= circlen)
    {
        cursum += (ee[q] - ee[0]) * circ[q % m].c;
        curcnt += circ[q % m].c;
        ++q;
    }
    for (int i = q; i < m; ++i)
    {
        cursum += (circlen - (ee[i] - ee[0])) * circ[i % m].c;
    }
    for (int i = 0; i < m; ++i)
    {
        while (2 * (ee[q] - ee[i]) <= circlen)
        {
            cursum -= (circlen - 2 * (ee[q] - ee[i])) * circ[q % m].c;
            curcnt += circ[q % m].c;
            ++q;
        }
        for (auto it = circ[i].v.begin(); it != circ[i].v.end(); ++it)
        {
            ans[*it] += cursum + total - circ[i].x + dd[*it] * (n - circ[i].c);
        }
        curcnt -= circ[i].c;
        cursum += (n - curcnt) * circ[i].e;
        cursum -= curcnt * circ[i].e;
    }
}

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0;
	char ch;
	do ch = nc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;
}

int main()
{
    int n, m, a, b, c;

    n = read();
	for (int i = 0; i < n; ++i)
    {
    	a = read() - 1, b = read() - 1, c = read();
        e[a].push_back(std::make_pair(b, c));
        e[b].push_back(std::make_pair(a, c));
    }

    m = findcirc(n);
    for (int i = 0; i < m; ++i)
    {
        calctree(circ[i]);
    }
    calccirc(n, m);

    for (int i = 0; i < n; ++i)
    {
        printf("%lld%c", ans[i], i == n - 1 ? '\n' : ' ');
    }

    return 0;
}