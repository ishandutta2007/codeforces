#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
const int N = 500;

int a[N];
vector <int> x1, x2;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ans = -2e9;
    for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++)
    {
        x1.clear();
        x2.clear();
        for (int o = 1; o <= n; o++) if (i <= o && o <= j) x1.push_back(a[o]); else x2.push_back(a[o]);
        sort(x1.begin(), x1.end());
        sort(x2.begin(), x2.end());
        int sum = 0;
        for (int o = 0; o < x1.size(); o++) sum += x1[o];
        int l = 0, r = x2.size() - 1;
        for (int p = 1; p <= k; p++)
        {
            if (l == x1.size() || r < 0 || x1[l] > x2[r])  break;
            sum += x2[r] - x1[l];
            l++, r--;
        }
        ans = max(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}