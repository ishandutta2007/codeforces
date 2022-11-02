#include<cstdio>
#include<algorithm>

using namespace std;
const int N = 100000;

int a[N];

int main() {
    int n, now, ans;
    now = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == i) now++;
    }
    ans = now;
    for (int i = 0; i < n; i++) {
        if (a[i] == i || a[a[i]] == a[i]) continue;
        int res = now + 1;
        if (a[a[i]] == i) res++;
        ans = max(ans, res);
    }
    printf("%d", ans);
    return 0;
}