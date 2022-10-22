#include <bits/stdc++.h>
using namespace std;

int N, arr[500005];
vector<int> V;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < N; i++) {
        int pos = lower_bound(V.begin(), V.end(), arr[i]) - V.begin();
        if (pos == V.size()) V.push_back(arr[i]);
        else V[pos] = arr[i];
    }
    printf("%d\n", V.size());
}