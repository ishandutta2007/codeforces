#include <iostream>
#include <cstdio>
using namespace std;
/*
inline int rev (int n)
{
    int r = 9;

    while (r < n)
        r = r * 10 + 9;

    return r - n;
}
*/
int L, R;

int main ()
{
    scanf ("%d %d", &L, &R);
    long long most = 0;

    for (long long p10 = 1; p10 <= R; p10 *= 10)
        if (L < 10 * p10)
        {
            long long lo = max ((long long) L, p10);
            long long hi = min ((long long) R, 10 * p10 - 1);
            most = max (most, lo * (10 * p10 - 1 - lo));
            most = max (most, hi * (10 * p10 - 1 - hi));

            if (lo <= 5 * p10 && 5 * p10 <= hi)
                most = max (most, 5 * p10 * (5 * p10 - 1));
        }
/*
    long long nines = 9;

    while (nines < L)
        nines = nines * 10 + 9;

    long long most = 0, product = L * (nines - L);

    for (int i = L; i <= R; i++)
    {
        if (i > nines)
        {
            nines = nines * 10 + 9;
            product = i * (nines - i);
        }

        most = max (most, product);
        product += nines - 2 * i - 1;
    }
*/
    cout << most << '\n';
    return 0;
}