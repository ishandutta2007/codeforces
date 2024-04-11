#include<cstdio>
#include<algorithm>

using namespace std;
const int N = 100000 + 10;

int a[N], used[N], ans[N];
pair <int,int> l[N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d", &l[i].first);
        l[i].second = i;
    }
    sort(l, l + m);
    int cnt = 0;
    int i = n;
    for (int j = m - 1; j >= 0; j--) {
        while (i >= l[j].first) {
            if (used[a[i]] == 0) cnt++;
            used[a[i]] = 1;
            i--;
        }
        ans[l[j].second] = cnt;
    }
    for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
    return 0;
}