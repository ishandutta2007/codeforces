#include <bits/stdc++.h>
using namespace std;

int N, arr[300005], arr2[300005];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < N; i++) {
        while (arr[i] % 2 == 0) arr[i] /= 2;
        while (arr[i] % 3 == 0) arr[i] /= 3;
    }
    for (int i = 1; i < N; i++) {
        if (arr[i] != arr[i-1]) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
}