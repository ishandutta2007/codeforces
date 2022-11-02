#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair <int, int> pii;
typedef long long ll;

vector <pii> x;

int main() {
    int n, r, avg;
    scanf("%d %d %d", &n, &r, &avg);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        x.push_back(make_pair(b, a));
    }
    sort(x.begin(), x.end());
    ll need = 1LL * n * avg, ans = 0;
    for (int i = 0; i < n; i++) need -= x[i].second;
    for (int i = 0; need > 0; i++) {
        ll add = r - x[i].second;
        if (add > need) add = need;
        ans += add * x[i].first;
        need -= add;
    }
    printf("%I64d\n", ans);
    return 0;
}