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
const int N = 1000 + 10;
const int M = 10 + 1;

char a[N][M][M];
int g[N][N], dist[N], last[N];
vector <pii> res;
bool used[N];

int main()
{
    int n, m, k, w;
    scanf("%d %d %d %d", &n, &m, &k, &w);
    for (int guy = 1; guy <= k; guy++) for (int i = 0; i < n; i++) scanf("%s", &a[guy][i]);
    for (int x = 1; x <= k; x++) for (int y = x + 1; y <= k; y++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[x][i][j] != a[y][i][j]) sum += w;
        g[x][y] = g[y][x] = sum;
    }
    dist[0] = 1e9;
    for (int i = 1; i <= k; i++) dist[i] = n * m, last[i] = 0;
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        int nom = 0;
        for (int j = 1; j <= k; j++) if (!used[j] && dist[j] < dist[nom]) nom = j;
        used[nom] = true;
        ans += dist[nom];
        res.push_back(make_pair(nom, last[nom]));
        for (int j = 1; j <= k; j++) if (dist[j] > g[nom][j]) dist[j] = g[nom][j], last[j] = nom;
    }
    printf("%d\n", ans);
    for (int i = 0; i < res.size(); i++) printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}