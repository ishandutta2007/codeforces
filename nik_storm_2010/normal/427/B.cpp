#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
const int N = 300000;

multiset <int> base;
int a[N];

int main()
{
    int n, t, c;
    scanf("%d %d %d", &n, &t, &c);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= c; i++) base.insert(a[i]);
    int ans = 0;
    multiset <int>::iterator it = base.end();
    it--;
    if (*it <= t) ans++;
    for (int i = c + 1; i <= n; i++)
    {
        base.erase(base.find(a[i - c]));
        base.insert(a[i]);
        it = base.end();
        it--;
        if (*it <= t) ans++;
    }
    printf("%d\n", ans);
    return 0;
}