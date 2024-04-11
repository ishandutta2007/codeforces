#include <bits/stdc++.h>
using namespace std;

int N, M, arr[300005];

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    sort(arr,arr+N);
    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        if (i) printf(" ");
        printf("%d",upper_bound(arr, arr+N, x)-arr);
    }
    printf("\n");
}