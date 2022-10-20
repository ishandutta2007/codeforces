#include <bits/stdc++.h>

using namespace std;
const int N = 200010;

int n, k;
char a[N];
char res[N];

int main() {
    scanf("%d %d", &n, &k);
    scanf("%s", a + 1);
    int has = k / 2;
    int cntRes = 0;
    int now = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == '(') {
            if (has) {
                has--;
                res[++cntRes] = a[i];
                now++;
            }
        } else {
            if (now == 0) {
                continue;
            } else {
                res[++cntRes] = a[i];
                now--;
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        printf("%c", res[i]);
    }
    printf("\n");
    return 0;
}