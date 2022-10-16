#include<stdio.h>
#define N (100000 + 10)

int a[N];
int n;

int main() {
    int i;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", a + i);
    int cnt_odd = 0;
    for(i = 0; i < n; i++)
        if(a[i] % 2 == 1) cnt_odd++;
    int cnt_even = n - cnt_odd;
    if(cnt_odd <= cnt_even) { printf("%d\n", cnt_odd); return 0; }

    printf("%d\n", cnt_even + (cnt_odd - cnt_even) / 3);
    return 0;
}