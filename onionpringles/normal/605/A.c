#pragma warning(disable:4996)

#include <stdio.h>

int dat[100000];
int rev[100000];
int ln[100000];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        x--;
        dat[i] = x;
        rev[x] = i;
    }
    ln[0] = 1; int M = 1;
    for (int i = 1; i < n; i++) {
        if (rev[i] < rev[i - 1]) ln[i] = 1;
        else {
            ln[i] = ln[i - 1] + 1;
        }
        if (ln[i] > M) M = ln[i];
    }
    printf("%d", n - M);
    
}