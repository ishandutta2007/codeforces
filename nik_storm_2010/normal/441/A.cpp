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
const int N = 100;

bool used[N];

int main()
{
    int n, v;
    scanf("%d %d", &n, &v);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int k, small = 1e9;
        scanf("%d", &k);
        for (int j = 1; j <= k; j++)
        {
            int x;
            scanf("%d", &x);
            small = min(small, x);
        }
        if (small + 1 <= v) ans++, used[i] = true;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) if (used[i]) printf("%d ", i);
    printf("\n");
    return 0;
}