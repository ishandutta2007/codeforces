#include <cstdio>
#include <cstring>
using namespace std;

const int N_MAX = 100005;

int N, L, T, best[N_MAX];

int main()
{
    memset(best, 63, sizeof(best));
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &T);
        int lo = 0, hi = L, mid;

        while (lo < hi)
        {
            mid = (lo + hi) >> 1;

            if (best[mid] < T)
                lo = mid + 1;
            else
                hi = mid;
        }

        best[lo] = T;

        if (lo == L)
            L++;
    }

    printf("%d\n", L);
    return 0;
}