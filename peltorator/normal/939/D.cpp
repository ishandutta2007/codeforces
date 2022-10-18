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
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <deque>

#define deb(a) cerr << #a << " = " << (a) << "\n"
#define deb2(a, b) deb(a); deb(b)
#define deb3(a, b, c) deb(a); deb(b); deb(c)
#define deb4(a, b, c, d) deb(a); deb(b); deb(c); deb(d)

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 100;

vector<int> g[MAXN];
int used[MAXN];
vector<int> a, b;

void dfs(int v)
{
    used[v] = 1;
    for (int u : g[v])
        if (!used[u])
        {
            a.push_back(v);
            b.push_back(u);
            dfs(u);
        }
}

int main()
{
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < n; i++)
        if (s[i] != t[i])
        {
            g[s[i] - 'a'].push_back(t[i] - 'a');
            g[t[i] - 'a'].push_back(s[i] - 'a');
        }
    for (int i = 0; i < 26; i++)
        if (!used[i])
            dfs(i);
    cout << a.size();
    for (int i = 0; i < a.size(); i++)
        cout << "\n" << (char)(a[i] + 'a') << " " << (char)(b[i] + 'a');
    return 0;
}