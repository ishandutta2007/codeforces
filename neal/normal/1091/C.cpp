#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

long long N;
set<long long> fun_values;

void add_factor(long long jump) {
    long long count = N / jump;
    fun_values.insert(count + count * (count - 1) / 2 * jump);
}

int main() {
    scanf("%lld", &N);

    for (long long i = 1; i * i <= N; i++)
        if (N % i == 0) {
            add_factor(i);

            if (i * i < N)
                add_factor(N / i);
        }

    vector<long long> output(fun_values.begin(), fun_values.end());
    int size = output.size();

    for (int i = 0; i < size; i++)
        printf("%lld%c", output[i], i < size - 1 ? ' ' : '\n');
}