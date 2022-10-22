#include <bits/stdc++.h>
using namespace std;

int N, arr[1000005], freq[2000005];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < N; i++) freq[arr[i]]++;
    for (int i = 0; i <= 2000000; i++) {
        int up = freq[i] / 2;
        freq[i] %= 2;
        freq[i + 1] += up;
    }
    int sum = 0;
    for (int i = 0; i <= 2000001; i++) sum += freq[i];
    printf("%d\n", sum);
}