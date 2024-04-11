#include <cstdio>
using namespace std;

const int MOD = 1000003;

int n, empty = 1;

int main ()
{
    scanf ("%d", &n);

    while (n-- > 1)
        empty = 3 * empty % MOD;

    printf ("%d\n", empty);
    return 0;
}