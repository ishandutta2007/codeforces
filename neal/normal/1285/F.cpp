#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e5 + 5;

bool have[MAX];
vector<int> divisors[MAX];
int8_t mobius[MAX];
int count_multiples[MAX];

int count_relatively_prime_with(int x) {
    int sum = 0;

    for (int d : divisors[x])
        sum += mobius[d] * count_multiples[d];

    return sum;
}

void remove(int x) {
    for (int d : divisors[x])
        count_multiples[d]--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i < MAX; i++)
        for (int j = i; j < MAX; j += i)
            divisors[j].push_back(i);

    mobius[1] = 1;

    for (int i = 1; i < MAX; i++)
        for (int j = 2 * i; j < MAX; j += i)
            mobius[j] -= mobius[i];

    int N;
    cin >> N;
    long long answer = 0;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        have[a] = true;
        answer = max(answer, (long long) a);
    }

    for (int i = MAX - 1; i > 0; i--)
        if (!have[i])
            for (int j = 2 * i; j < MAX; j += i)
                if (have[j]) {
                    have[i] = true;
                    break;
                }

    for (int i = 1; i < MAX; i++)
        for (int j = i; j < MAX; j += i)
            count_multiples[i] += have[j];

    vector<int> numbers;

    for (int i = MAX - 1; i > 0; i--)
        if (have[i])
            numbers.push_back(i);

    int first = 0, last = (int) numbers.size() - 1;

    while (first < last) {
        int relatively_prime = count_relatively_prime_with(numbers[first]);

        while (first < last && relatively_prime > 0) {
            if (__gcd(numbers[first], numbers[last]) == 1) {
                answer = max(answer, (long long) numbers[first] * numbers[last]);
                relatively_prime--;
            }

            remove(numbers[last]);
            last--;
        }

        remove(numbers[first]);
        first++;
    }

    cout << answer << '\n';
}