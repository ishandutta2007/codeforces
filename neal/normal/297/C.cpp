#include <cstdio>
#include <algorithm>
using namespace std;

const int N_MAX = 100005;

int N, numbers[N_MAX], A[N_MAX], B[N_MAX];
int A_out[N_MAX], B_out[N_MAX];
pair<int, int> data[N_MAX];

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &data[i].first);
        data[i].second = i;
    }

    sort(data, data + N);

    for (int i = 0; i < N; i++)
        numbers[i] = data[i].first;

    int a = 0, b = N / 3;
    int pos = lower_bound(numbers, numbers + N, a + b) - numbers;

    for (int i = 0; i < pos; i++)
    {
        A[i] = numbers[i];
        B[i] = 0;
    }

    while (pos < N)
    {
        if (b < a)
        {
            b++;
            a = numbers[pos] - b;
        }
        else
            b = numbers[pos] - a;

        A[pos] = a;
        B[pos] = b;
        swap(a, b);
        pos++;
    }

    for (int i = 0; i < N; i++)
    {
        A_out[data[i].second] = A[i];
        B_out[data[i].second] = B[i];
    }

    puts("YES");

    for (int i = 0; i < N; i++)
        printf("%d%c", A_out[i], i < N - 1 ? ' ' : '\n');

    for (int i = 0; i < N; i++)
        printf("%d%c", B_out[i], i < N - 1 ? ' ' : '\n');

    return 0;
}