#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;
#define MAXN 100002

int n, m, k;
int arr1[MAXN];
int arr2[MAXN];

int main() {
    scanf("%d %d %d", &n, &m, &k);
    if (n > m) puts("YES");
    else {
        for (int i=0; i<n; i++) scanf("%d", &arr1[i]);
        for (int i=0; i<m; i++) scanf("%d", &arr2[i]);

        sort(arr1, arr1+n, greater<int>());
        sort(arr2, arr2+m, greater<int>());

        for (int i=0; i<n; i++) if (arr1[i] > arr2[i]) {
            puts("YES");
            return 0;
        }

        puts("NO");
    }
    return 0;
}