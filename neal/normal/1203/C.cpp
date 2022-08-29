#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    long long G = 0;

    while (N-- > 0) {
        long long a;
        cin >> a;
        G = __gcd(G, a);
    }

    int answer = 0;

    for (long long p = 1; p * p <= G; p++)
        if (G % p == 0) {
            answer++;

            if (p * p < G)
                answer++;
        }

    cout << answer << '\n';
}