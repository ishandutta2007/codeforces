#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 4055;
const int INF = 0x3f3f3f3f;

int A[N], B[N], P[N];
int n;
bool appears[N];

bool check() {
    memset(appears, 0, sizeof appears);

    int matchA = 0, matchB = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == P[i]) ++matchA;
        if (B[i] == P[i]) ++matchB;
        appears[P[i]] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (!appears[i]) {
            return false;
        }
    }

    return matchA == n - 1 && matchB == n - 1;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", A + i);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", B + i);
    }

    int a = -1, b = -1 , sum = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == B[i]) {
            P[i] = A[i];
            sum += A[i];
        }
        else {
            if (a == -1) {
                a = i;
            }
            else {
                b = i;
            }
        }
    }

    if (a == -1) {
        printf("idiot nub wot ar u doing\n");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (b == -1) {
            P[a] = i;
            if (check()) {
                for (int k = 0; k < n; k++) {
                    printf("%d ", P[k]);
                }
                printf("\n");
                return 0;
            }
            continue;
        }
        int j = (n * n + n)/2 - (sum + i);
        if (j < 0) {
            printf("nooooob\n");
            return 0;
        }
        P[a] = i;
        P[b] = j;
        if (check()) {
            for (int k = 0; k < n; k++) {
                printf("%d ", P[k]);
            }
            printf("\n");
            return 0;
        }
    }
    return 0;
}