#include <bits/stdc++.h>

using namespace std;

#define ll long long

int a00, a01, a10, a11;

void solve(int a, int b) {
    if (a * 1LL * b - a01 != a10) {
        return;
    }
    
    if (a == 0) {
        for (int i = 0; i < b; i++) {
            printf("1");
        }
        printf("\n");
        exit(0);
    }
    
    if (b == 0) {
        for (int i = 0; i < a; i++) {
            printf("0");
        }
        printf("\n");
        exit(0);
    }
    
    int x = a01 / b;
    int y = a01 % b;
    
    for (int i = 0; i < x; i++) {
        printf("0");
    }
    for (int i = 0; i < b - y; i++) {
        printf("1");
    }
    if (x < a) {
        printf("0");
    }
    for (int i = 0; i < y; i++) {
        printf("1");
    }
    for (int i = 0; i < a - x - 1; i++) {
        printf("0");
    }
    printf("\n");
    exit(0);
}

int f(int x) {
    int y = 0;
    while (y * (y - 1) / 2 < x) {
        y++;
    }
    
    if (y * (y - 1) / 2 != x) {
        return -1;
    }
    
    return y;
}

void NO() {
    printf("Impossible\n");
    exit(0);
}

int main() {
    scanf("%d%d%d%d", &a00, &a01, &a10, &a11);
    
    int a = f(a00);
    int b = f(a11);
    
    if (a == -1 || b == -1) {
        NO();
    }
    
    if (a00 == 0) {
        if (a11 == 0) {
            solve(0, 1);
            solve(1, 0);
            solve(1, 1);
        } else {
            solve(0, b);
            solve(1, b);
        }
    } else {
        if (a11 == 0) {
            solve(a, 0);
            solve(a, 1);
        } else {
            solve(a, b);
        }
    }
    
    NO();
    
    return 0;
}