#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N_MAX = 100005;

int N, A[N_MAX];

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i + 1]);

    A[0] = 0;
    N++;
    sort(A, A + N);
    long long sum = 0, total = 0;

    for (int i = 0; i < N; i++)
    {
        total += (long long) i * A[i] - sum;
        sum += A[i];
    }

    long long num = 2 * total - sum, den = N - 1;
    long long g = __gcd(num, den);
    num /= g;
    den /= g;
    cout << num << ' ' << den << '\n';
    return 0;
}