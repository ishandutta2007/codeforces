#include <bits/stdc++.h>
using namespace std;

int n, k;

long long a, b;

long long ost;
queue <long long> kol;

int main()
{
    scanf("%d%d", &n, &k);
    k++;
    for (int i=1; i<=n; i++)
    {
        scanf("%lld%lld", &a, &b);
        ost=max(ost, a);
        while(!kol.empty() && kol.front()<=a)
        kol.pop();
        if (kol.size()==k)
        {
            printf("-1 ");
            continue;
        }
        ost+=b;
        printf("%lld ", ost);
        kol.push(ost);
    }
    printf("\n");
    return 0;
}