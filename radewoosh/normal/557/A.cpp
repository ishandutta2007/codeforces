#include <cstdio>
using namespace std;

int n;

int mini[4];
int maxi[4];

int x;

int main()
{
    scanf("%d", &n);
    scanf("%d%d", &mini[1], &maxi[1]);
    scanf("%d%d", &mini[2], &maxi[2]);
    scanf("%d%d", &mini[3], &maxi[3]);
    x=n-mini[2]-mini[3];
    if (x>maxi[1])
    {
        x=maxi[1];
    }
    n-=x;
    printf("%d ", x);

    x=n-mini[3];
    if (x>maxi[2])
    {
        x=maxi[2];
    }
    printf("%d %d", x, n-x);
    return 0;
}