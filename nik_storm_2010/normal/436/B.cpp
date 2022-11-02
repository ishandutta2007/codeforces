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
const int N = 3000;

char a[N][N];
int ans[N];

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) scanf("%s", &a[i]);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        if (a[i][j] == 'U' && (i % 2 == 0)) ans[j]++;
        if (a[i][j] == 'D') continue;
        if (a[i][j] == 'L')
        {
            int y = j - i;
            if (y >= 0) ans[y]++;
        }
        if (a[i][j] == 'R')
        {
            int y = j + i;
            if (y < m) ans[y]++;
        }
    }
    for (int i = 0; i < m; i++) printf("%d ", ans[i]);
    return 0;
}