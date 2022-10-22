#include <bits/stdc++.h>
using namespace std;

int N, arr[1000005], arr2[1000005], count1[1000005];
vector<int> ans;

int gcd(int x, int y) {
    if (min(x, y) == 0) return max(x, y);
    return gcd(max(x, y) % min(x, y), min(x, y));
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N * N; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < N * N; i++) arr2[i] = arr[i];
    sort(arr, arr + N * N);
    int len = unique(arr, arr + N * N) - arr;
    for (int i = 0; i < N * N; i++) count1[lower_bound(arr, arr + len, arr2[i]) - arr]++;
    for (int i = len - 1; i >= 0; i--) {
        while (true) {
            if (count1[i] == 0) break;
            ans.push_back(arr[i]);
            count1[i]--;
            //for (int j = 0; j < 10000000; j++) 0+0;
            for (int j = 0; j + 1 < ans.size(); j++) {
                count1[lower_bound(arr, arr + len, gcd(ans[j], arr[i])) - arr] -= 2;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}