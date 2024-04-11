#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 30;

vector <int> ans;
int cnt[N], used[N];

int lowbit(int x)
{
    for (int i = 0; i < N; i++) if (x & (1 << i)) return i;
}

bool build(int x, int need)
{
    if (x == -1) return false;
    int have = min(cnt[x] - used[x], need);
    used[x] += have;
    need -= have;
    if (need == 0) return true; else return build(x - 1, need * 2);
}

int main()
{
    int sum, limit;
    scanf("%d %d", &sum, &limit);
    for (int i = 1; i <= limit; i++)
    {
        int x = lowbit(i);
        cnt[x]++;
    }
    for (int i = 0; i < N; i++) if (sum & (1 << i))
    {
        bool ok = build(i, 1);
        if (!ok)
        {
            puts("-1");
            return 0;
        }
    }
    for (int i = 1; i <= limit; i++)
    {
        int x = lowbit(i);
        if (used[x] == 0) continue;
        used[x]--;
        ans.push_back(i);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    return 0;
}