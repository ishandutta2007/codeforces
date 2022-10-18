#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1000000;

ll kk[MAXN], bb[MAXN];

vector<ll> k[MAXN], b[MAXN];

ld f(ld k1, ld b1, ld k2, ld b2)
{
    return (b1 - b2) / (k2 - k1);
}

void addLine(int v, ll k1, ll b1)
{
    while (k[v].size() > 1)
    {
        ld cur = f(k1, b1, k[v].back(), b[v].back());
        ld was = f(k[v].back(), b[v].back(), k[v][k[v].size() - 2], b[v][b[v].size() - 2]);
        if (k1 == k[v].back() || cur < was)
        {
            k[v].pop_back();
            b[v].pop_back();
        }
        else
            break;
    }
    if (k[v].size() && k[v].back() == k1)
    { 
        k[v].pop_back();
        b[v].pop_back();
    }
    k[v].push_back(k1);
    b[v].push_back(b1);
}

void merge(int v)
{
    int i = 0, j = 0;
    while (i < k[2 * v].size() || j < k[2 * v + 1].size())
    {
        if (i >= k[2 * v].size() || (j < k[2 * v + 1].size() && 
                    (k[2 * v + 1][j] > k[2 * v][i] || (k[2 * v + 1][j] == k[2 * v][i] && b[2 * v + 1][j] > b[2 * v][i]))))
        {
            addLine(v, k[2 * v + 1][j], b[2 * v + 1][j]);
            j++;
        }
        else
        {
            addLine(v, k[2 * v][i], b[2 * v][i]);
            i++;
        }
    }
}

void buildtree(int v, int l, int r)
{
    if (r < l)
        return;
    k[v].clear();
    b[v].clear();
    if (l == r)
    {
        k[v].push_back(kk[l]);
        b[v].push_back(bb[l]);
        return;
    }
    int mid = (r + l) / 2;
    buildtree(2 * v, l, mid);
    buildtree(2 * v + 1, mid + 1, r);
    merge(v);
}

ll tf(int v, int l, int r, int ql, int qr, ll x)
{
    if (r < l || ql > r || l > qr)
        return 1e18;
    if (ql <= l && r <= qr)
    {
      //  cout << "...." << l << " " << r << "...\n";
       // for (int i = 0; i < k[v].size(); i++)
         //   cout << k[v][i] << " " << b[v][i] << endl;
        int left = 0, right = k[v].size();
        while (right - left > 1)
        {
            int mid = (right + left) / 2;
            if (f(k[v][mid - 1], b[v][mid - 1], k[v][mid], b[v][mid]) > (ld)x)
                right = mid;
            else
                left = mid;
        }
        return k[v][left] * x + b[v][left];
    }
    int mid = (r + l) / 2;
    return min(tf(2 * v, l, mid, ql, qr, x), tf(2 * v + 1, mid + 1, r, ql, qr, x));
}

int main()
{
  //  freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	vector<ll> a(n + 1, 0), sum(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
        kk[i] = a[i];
        bb[i] = i * a[i] - sum[i];
    }
   //return 0;
    buildtree(1, 1, n);
   // return 0;
    int m;
	cin >> m;
//    return 0;
    vector<ll> ans(m);
    for (int k = 0; k < m; k++)
    {
        int i, j;
        cin >> i >> j;
       // return 0;
        ans[k] = sum[j] + tf(1, 1, n, max(1, j - i), j, i - j);
        //cout << "-----------\n";
      //return 0;
    }
 //   return 0;
    for (int i = 0; i < m; i++)
        cout << ans[i] << "\n";
    return 0; 
}