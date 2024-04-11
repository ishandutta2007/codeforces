#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef double ld;

vector<int> cnt, p, pn, c, cn;

const char C = 'a' - 1;

void sufarr(string s)
{
    int n = s.size();
    for (char i = C; i <= 'z'; i++)
        for (int j = 0; j < n; j++)
            if (s[j] == i)
                p.push_back(j);
    c.assign(n, 0);
    cn.assign(n, 0);
    for (int i = 0; i < n; i++)
        c[i] = s[i] - C;
    pn.assign(n, 0);
    int maxc = 29;
    for (int k = 1; k < n; k *= 2)
    {
        for (int i = 0; i < n; i++)
            pn[i] = (p[i] - k + n) % n;
        cnt.assign(maxc + 2, 0);
        for (int i = 0; i < n; i++)
            cnt[c[i] + 1]++;
        for (int i = 1; i <= maxc + 1; i++)
            cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; i++)
            p[cnt[c[pn[i]]]++] = pn[i];
        cn[0] = 0;
        for (int i = 1; i < n; i++)
            if (c[p[i]] == c[p[i - 1]] && c[(p[i] + k) % n] == c[(p[i - 1] + k) % n])
                cn[p[i]] = cn[p[i - 1]];
            else
                cn[p[i]] = cn[p[i - 1]] + 1;
        c = cn;
        maxc = c[p[n - 1]];
    }
}

vector<int> lcp, mem;

const int N = 200001, LOG = 23;

int sp[LOG][N], logs[N];

int f(int l, int r)
{
    int x = logs[r - l + 1];
    return min(sp[x][l], sp[x][r - (1 << x) + 1]);
}

int pref[N];

int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    string s, t;
    int nn;
    cin >> nn;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int cur = 0;
    for (int i = 0; i < N; i++)
    {
        if ((1 << (cur + 1))  == i)
            cur++;
        logs[i] = cur;
    }
    s += C;
    t += '1';
    sufarr(s);
    int n = s.size();
    mem.assign(n, 0);
    lcp.assign(n, 0);
    for (int i = 0; i < n; i++)
        mem[p[i]] = i;
    for (int i = 0; i < n; i++)
    {
        if (mem[i] == n - 1)
            continue;
        if (i)
            lcp[mem[i]] = max(lcp[mem[i - 1]] - 1, 0);
        while (max(i + lcp[mem[i]], p[mem[i] + 1] + lcp[mem[i]]) < n && 
                s[i + lcp[mem[i]]] == s[p[mem[i] + 1] + lcp[mem[i]]])
            lcp[mem[i]]++;
    }
    for (int i = 0; i < n; i++)
        sp[0][i] = lcp[i];
    for (int i = 1; i < LOG; i++)
        for (int j = 0; j < n; j++)
        {
            sp[i][j] = sp[i - 1][j];
            if ((1 << (i - 1)) + j < n)
                sp[i][j] = min(sp[i][j], sp[i - 1][j + (1 << (i - 1))]);
        }
    pref[0] = (t[p[0]] == '0' ? 1 : 0);
    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + (t[p[i]] == '0' ? 1 : 0);
    ll ans = 0;
    for (int i = 0; i < n; i++)
        if (t[i] == '0')
        {
            ans = n - i - 1;
            break;
        }
    for (int i = 1; i < n; i++)
    {
        int l = -1, r = i;
        while (r - l > 1)
        {
            int mid = (r + l) / 2;
            if (f(mid, i) >= lcp[i])
                r = mid;
            else
                l = mid;
        }
        int L = r;
        l = i, r = n;
        while (r - l > 1)
        {
            int mid = (r + l) / 2;
            if (f(i, mid) >= lcp[i])
                l = mid;
            else
                r = mid;
        }
        int R = l + 1;
        int cur = pref[R];
        if (L)
            cur -= pref[L - 1];
        ans = max(ans, (ll)lcp[i] * (ll)cur);
    }
    cout << ans;
    return 0;
}