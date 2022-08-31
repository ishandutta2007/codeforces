#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N_MAX = 10005;
const int HASH_MULT = 9987287;

int N;
char str[N_MAX], rev_str[N_MAX];
long long hash_pow[N_MAX], str_hash[N_MAX], rev_hash[N_MAX];
int odd[N_MAX], even[N_MAX];

void compute_hash(char *s, long long *h)
{
    h[0] = 0;

    for (int i = 0; i < N; i++)
        h[i + 1] = h[i] * HASH_MULT + s[i];
}

long long get_hash(long long *h, int start, int end)
{
    return h[end] - h[start] * hash_pow[end - start];
}

bool is_palindrome(int start, int end)
{
    return get_hash(str_hash, start, end) == get_hash(rev_hash, N - end, N - start);
}

int count_palindromes(int start, int end)
{
    int count = 0;

    for (int i = start; i < end; i++)
        count += min(odd[i], min(i + 1 - start, end - i));

    for (int i = start; i + 1 < end; i++)
        count += min(even[i], min(i + 1 - start, end - (i + 1)));

    return count;
}

int count_start(int start)
{
    int count = 0;

    for (int i = start; i < N; i++)
        if (i - odd[i] + 1 <= start && i + odd[i] <= N)
            count++;

    for (int i = start; i + 1 < N; i++)
        if (i - even[i] + 1 <= start && i + 1 + even[i] <= N)
            count++;

    return count;
}

int main()
{
    scanf("%s", str);
    N = strlen(str);

    for (int i = 0; i < N; i++)
        rev_str[i] = str[N - 1 - i];

    hash_pow[0] = 1;

    for (int i = 0; i < N; i++)
        hash_pow[i + 1] = hash_pow[i] * HASH_MULT;

    compute_hash(str, str_hash);
    compute_hash(rev_str, rev_hash);
/*
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j <= N; j++)
            printf("%d %d %lld\n", i, j, get_hash(str_hash, i, j));
*/
    for (int i = 0; i < N; i++)
    {
        int lo = 0, hi = min(i + 1, N - 1);

        while (lo < hi)
        {
            int mid = (lo + hi + 1) / 2;

            if (is_palindrome(i - mid + 1, i + mid))
                lo = mid;
            else
                hi = mid - 1;
        }

        odd[i] = lo;
//        printf("%d\n", odd[i]);
    }

    for (int i = 0; i < N - 1; i++)
    {
        int lo = 0, hi = min(i + 1, N - (i + 1));

        while (lo < hi)
        {
            int mid = (lo + hi + 1) / 2;

            if (is_palindrome(i - mid + 1, i + 1 + mid))
                lo = mid;
            else
                hi = mid - 1;
        }

        even[i] = lo;
//        printf("%d\n", even[i]);
    }

    long long total = 0;

    for (int i = 0; i < N; i++)
    {
//        printf("%d %d\n", count_palindromes(0, i), count_start(i));
        total += (long long) count_palindromes(0, i) * count_start(i);
    }

    cout << total << '\n';
    return 0;
}