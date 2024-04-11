#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int all = (1 << K) - 1;
    map<int, int> freq;
    freq[0]++;
    int running_xor = 0;
    long long total = 0;

    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        running_xor ^= a;

        if (freq[running_xor ^ all] < freq[running_xor])
            running_xor ^= all;

        total += i + 1 - freq[running_xor];
        freq[running_xor]++;
    }

    printf("%lld\n", total);
}