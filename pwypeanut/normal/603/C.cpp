#include <bits/stdc++.h>
using namespace std;

int N, K;

int rec(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (x == 2) return 0;
    if (x == 3) return 1;
    if (x == 4) return 2;
    if (x % 2 == 1) return 0;
    else {
        int val = rec(x/2);
        if (val == 0) return 1;
        if (val == 1) return 2;
        if (val == 2) return 1;
    }
}

int main() {
    scanf("%d%d", &N, &K);
    if (K % 2 == 0) {
        int ans = 0;
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            if (x == 0) ans ^= 0;
            else if (x == 1) ans ^= 1;
            else if (x == 2) ans ^= 2;
            else {
                if (x % 2 == 0) ans ^= 1;
            }
        }
        if (ans == 0) printf("Nicky\n");
        else printf("Kevin\n");
    } else {
        int ans = 0;
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            ans ^= rec(x);
        }
        if (ans == 0) printf("Nicky\n");
        else printf("Kevin\n");
    }
}