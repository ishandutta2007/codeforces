#pragma GCC optmize("Ofast")
#include <bits/stdc++.h>

int n, p[1005], flag[1005];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", p + i);
    for (int i = 1; i <= n; ++i) {
        int ptr = i;
        memset(flag, 0, sizeof(flag));
        while(!flag[ptr]) {
            flag[ptr] = 1;
            ptr = p[ptr]; 
        }
        printf("%d\n", ptr);
    }
}