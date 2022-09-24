#include<cstdio>
#include<algorithm>
using namespace std;


int n, x;
int a[100010], b[100010];
int main() {
    scanf("%d%d", &n, &x);
    for (int i=0; i<n; i++) scanf("%d", a+i);
    for (int i=0; i<n; i++) scanf("%d", b+i);
    sort(a, a+n);
    sort(b, b+n);
    int cnt=0;
    for (int p=0, q=n-1; p<n; p++) {
        if (a[p]+b[q]>=x) {
            cnt++;
            q--;
        }
    }
    printf("1 %d\n", cnt);


    return 0;
}