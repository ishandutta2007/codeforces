#include <bits/stdc++.h>
using namespace std;

int N, arr[200005], ans[200005];
priority_queue< int, vector<int>, greater<int> > PQ;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < N; i++) PQ.push(arr[i] + i);
    for (int i = 0; i < N; i++) {
        ans[i] = PQ.top() - i;
        PQ.pop();
        if (i > 0) {
            if (ans[i-1] > ans[i]) {
                printf(":(\n");
                return 0;
            }
        }
    }
    for (int i = 0; i < N; i++) printf("%d ", ans[i]);
    printf("\n");
}