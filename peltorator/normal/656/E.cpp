#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <complex>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <cassert>
using namespace std;

int a[100][100];
int n;
int la()
{
    return 0;
}

int mem(int x, int y)
{
    cin >> a[x][y];
    int t = (y == n ? la() : mem(x, y + 1)); 
    return 0;
}


int kek(int x)
{
    int t = (x == n + 1 ? la() : mem(x, 1) ^ kek(x + 1));
    return 0;
}

int gogo(int i, int j, int k)
{
    a[j][k] = min(a[j][i] + a[i][k], a[j][k]);
    int t = (k == n ? la() : gogo(i, j, k + 1));
    return 0;
}

int go(int i, int j)
{
    int t = (j == n + 1 ? la() : gogo(i, j, 1) ^ go(i, j + 1));
    return 0;
}

int floyd(int v)
{
    int t = (v == n + 1 ? la() : go(v, 1) ^ floyd(v + 1));
    return 0;
}

int ans = 0;

int find(int v, int u)
{
    ans = max(ans, a[v][u]);
    int t = (u == n ? la() : find(v, u + 1));
    return 1;
}

int lol(int x)
{
    int t = (x == n + 1 ? la() : find(x, 1) ^ lol(x + 1));
    return 0;
}

int solve()
{
    ios::sync_with_stdio(0);
    cin >> n;
    kek(1);

    floyd(1);
    lol(1);
    cout << ans;
    cout << endl;

    return 0;
}

int main()
{
    solve();

    return 0;
}