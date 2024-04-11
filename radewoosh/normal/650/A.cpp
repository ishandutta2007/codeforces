#include <bits/stdc++.h>
using namespace std;

int n;

int x, y;

map <int,int> raz;
map <int,int> dwa;
map <pair <int,int>,int> og;

long long wyn;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d%d", &x, &y);
        wyn+=raz[x];
        wyn+=dwa[y];
        wyn-=og[make_pair(x, y)];
        raz[x]++;
        dwa[y]++;
        og[make_pair(x, y)]++;
    }
    printf("%lld\n", wyn);
    return 0;
}