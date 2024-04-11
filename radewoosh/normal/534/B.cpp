#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int v1, v2;

int t, d;

long long dyn[3007][107];

int main()
{
    scanf("%d%d", &v1, &v2);
    scanf("%d%d", &t, &d);
    dyn[v1][1]=v1;
    for (int i=1; i<t; i++)
    {
        for (int j=0; j<=2900; j++)
        {
            if (!dyn[j][i])
            continue;
            for (int k=max(0, j-d); k<=j+d; k++)
            {
                dyn[k][i+1]=max(dyn[k][i+1], dyn[j][i]+k);
            }
        }
    }
    printf("%lld", dyn[v2][t]);
    return 0;
}