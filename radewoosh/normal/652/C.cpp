#include <bits/stdc++.h>
using namespace std;

int n, m;

int p1, p2;
int poz[1000007];

int mini[1000007];

vector <int> graf[1000007];

deque <int> kol;

long long wyn;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &p1);
        poz[p1]=i;
        mini[i]=n;
    }
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d", &p1, &p2);
        if (poz[p1]>poz[p2])
        swap(p1, p2);
        mini[poz[p1]]=min(mini[poz[p1]], poz[p2]-1);
    }
    for (int i=n; i; i--)
    {
        while(!kol.empty() && mini[i]<mini[kol.back()])
        kol.pop_back();
        kol.push_back(i);
        wyn+=mini[kol.front()]-i+1;
    }
    printf("%lld\n", wyn);
    return 0;
}