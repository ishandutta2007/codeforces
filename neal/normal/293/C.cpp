#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
using namespace std;

const int AB_MAX = 150005;

long long N, total = 0;

void add(long long a, long long b, long long c)
{
    assert(a <= b && b <= c);

    if (a == b && b == c)
        total++;
    else if (a == b ^ b == c)
        total += 3;
    else
        total += 6;
}

int main()
{
    cin >> N;

    if (N % 3 != 0)
    {
        cout << "0\n";
        return 0;
    }

    N /= 3;

    vector<int> factors;

    for (int i = 1; i < AB_MAX; i++)
        if (N % i == 0)
            factors.push_back(i);

    for (long long a = 1; 8 * a * a * a <= N; a++)
        for (int i = 0; i < (int) factors.size(); i++)
        {
            long long b = factors[i] - a;

            if (b < a)
                continue;

            if (2 * b * b * b + 4 * a * b * b + 2 * a * a * b > N)
                break;

            long long B = a + b, C = a * b - N / (a + b);
            long long D = B * B - 4 * C;
            long long S = sqrt(D + 0.5);

            if (S * S != D)
                continue;

            if ((S - B) % 2 != 0)
                continue;

            long long c = (S - B) / 2;

            if (c < b)
                continue;

            assert(c * c + B * c + C == 0);

            if (c >= b)
                add(a, b, c);
        }

    cout << total << '\n';
    return 0;
}