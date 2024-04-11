#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
typedef pair <int, int> pii;
const int N = 200000;

vector <pii> a;
bool m1[N], m2[N];

int main() {
    int n, x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        a.push_back(make_pair(x, +(i + 1)));
        a.push_back(make_pair(y, -(i + 1)));
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) if (a[i].second > 0) m1[a[i].second] = true; else m2[-a[i].second] = true;
    for (int i = 0; i < n; i++) if (i < n / 2 || m1[i + 1]) printf("1"); else printf("0");
    printf("\n");
    for (int i = 0; i < n; i++) if (i < n / 2 || m2[i + 1]) printf("1"); else printf("0");
    return 0;
}