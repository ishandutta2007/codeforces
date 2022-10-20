#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
vector<int> res[N];
int mx[N];
int a[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(mx + 1, mx + cur + 1, -a[i]) - mx;
//        cout << i << " " << pos << endl;
        if (pos == cur + 1) {
            cur++;
        }
        mx[pos] = -a[i];
        res[pos].push_back(a[i]);
    }
    for (int i = 1; i <= cur; i++) {
        for (int u : res[i]) {
            printf("%d ", u);
        }
        printf("\n");
    }
    return 0;
}