#include <iostream>
using namespace std;

const long long LL_INF = (long long) 2e18 + 5;

long long factorial_sum(long long n, long long p) {
    long long sum = 0;

    while (n != 0) {
        n /= p;
        sum += n;
    }

    return sum;
}

int main() {
    long long N, B;
    cin >> N >> B;
    long long answer = LL_INF;

    for (long long p = 2; p * p <= B; p++)
        if (B % p == 0) {
            int power = 0;

            do {
                B /= p;
                power++;
            } while (B % p == 0);

            answer = min(answer, factorial_sum(N, p) / power);
        }

    if (B > 1)
        answer = min(answer, factorial_sum(N, B));

    cout << answer << '\n';
}