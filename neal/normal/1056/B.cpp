#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long N, M;

long long count_mod(long long a) {
    return N / M + (a > 0 && a <= N % M ? 1 : 0);
}

int main() {
    cin >> N >> M;
    long long total = 0;

    for (int i = 0; i < M; i++)
        for(int j = 0; j < M; j++)
            if ((i * i + j * j) % M == 0)
                total += count_mod(i) * count_mod(j);

    cout << total << '\n';
}