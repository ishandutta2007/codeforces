#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A, B;

int main() {
    scanf("%d", &N);
    vector<int> location(N + 1, -1);

    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        location[a] = i;
    }

    int start = 0;

    for (int i = 0; i < N; i++) {
        int b;
        scanf("%d", &b);
        int take = max(location[b] - start + 1, 0);
        start += take;
        printf("%d%c", take, i < N - 1 ? ' ' : '\n');
    }
}