#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100];

int main() {
    scanf("%d", &n);
    bool slideoff = false;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        int indmax = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (abs(arr[j] - arr[j + 1]) > 1) {
                slideoff = true;
            }
        }
        for (int j = 0;j < n - i; j++) {
            if (arr[j] > arr[indmax]) {
                indmax = j;
            }
        }
        for (int j = indmax; j < n - i - 1; j++) {
            swap(arr[j], arr[j + 1]);
        }
    }
    if (slideoff) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
}