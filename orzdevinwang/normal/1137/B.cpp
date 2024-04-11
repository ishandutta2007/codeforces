#include<bits/stdc++.h>
#define N 510000
using namespace std;
int n, m, cnt, cntt, x, y, nex[N], ans;
bool cheak() {
    if(y < x || y < 0 || x < 0) return 0;
    return 1;
}
char a[N], b[N];
int main() {
    scanf("%s%s", b + 1, a + 1);
    y = m = strlen(b + 1), n = strlen(a + 1);
    for(int i = 1; i <= m; i++) x += (b[i] == '1');
    int j = 0;
    for(int i = 2; i <= n; i++) {
        while(a[i] != a[j + 1] && j > 0) j = nex[j];
        if(a[j + 1] == a[i]) j++;
        nex[i] = j;
    }
    for(int i = 1; i <= n; i++) cntt += (a[i] == '1');
    for(int i = nex[n] + 1; i <= n; i++) cnt += (a[i] == '1');
    y -= n, x -= cntt;
    if(!cheak()) {
        y += n, x += cntt;
        for(int i = 1; i <= x; i++) printf("1");
        for(int i = x + 1; i <= m; i++) printf("0");
        printf("\n");
        return 0;
    }
    printf("%s", a + 1);
    while(1) {
        ++ans, y -= n - nex[n], x -= cnt;
        if(!cheak()) {
            y += n - nex[n], x += cnt;
            for(int i = 1; i <= x; i ++) printf("1");
            for(int i = x + 1; i <= y; i++) printf("0");
            return 0;
        }
        printf("%s", a + nex[n] + 1);
    }
    return 0;
}