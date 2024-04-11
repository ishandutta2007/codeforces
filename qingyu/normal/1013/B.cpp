
#include<bits/stdc++.h>

int n,x,a[100100],b[100100], minn = 0x3f3f3f3f;
int main(void) {
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        if (*(b + *(a + i))) return printf("0"), 0;
        *(b + *(a + i)) = 1;
    } 
    for (int i = 1; i <= n; i++) {
        if (*(b + (*(a + i) & x ))&& (*(a + i) & x)!= *(a + i)) {minn = std::min(minn,*(b + (*(a + i) & x)));}  
        if (!*(b + (*(a + i) & x))) *(b + (*(a + i) & x))=2;
    }
    if (minn<=2) printf("%d", minn);
    else printf("-1");
    return 0;
}