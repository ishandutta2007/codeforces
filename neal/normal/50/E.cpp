#include <iostream>
#include <algorithm>
using namespace std;

const int BIG = 10000005;

long long N, M;
long long pairs = 0, irrat = 0;
bool solution [BIG + 5];

int main ()
{
    cin >> N >> M;

    for (long long b = 1; b <= N; b++)
        pairs += min (b * b, M);

    irrat = pairs;

    for (long long b = 1; b <= N; b++)
        for (long long b2 = b - 1; b2 >= 0; b2--)
        {
            long long c = b * b - b2 * b2;

            if (c <= M)
            {
                irrat--;
                solution [b - b2] = true;
                solution [b + b2] = true;
            }
            else
                break;
        }

    int int_sol = 0;

    for (int i = 0; i <= BIG; i++)
        if (solution [i])
            int_sol++;

    cout << 2 * irrat + int_sol << '\n';
    return 0;
}