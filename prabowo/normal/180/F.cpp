#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100002];

int main () {
    scanf("%d", &n);
    int a;
    for (int i=0; i<n; i++) {
        scanf("%d", &a);
        arr[a] = i + 1;
    }

    for (int i=0; i<n; i++) {
        scanf("%d", &a);
        printf("%d ", arr[a]);
    }

    printf("\n");
    return 0;
}