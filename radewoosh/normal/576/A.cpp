#include <bits/stdc++.h>
using namespace std;

int n;

int v;

int wyn;

vector <int> wek;
int sito[10007];

int main()
{
    scanf("%d", &n);
    for (int i=2; i<=n; i++)
    {
        v=i;
        if (sito[i])
        continue;
        for (int j=i; j<=n; j+=i)
        sito[j]=1;
        while(v<=n)
        {
            wyn++;
            wek.push_back(v);
            v*=i;
        }
    }
    printf("%d\n", wyn);
    for (int i=0; i<wek.size(); i++)
    {
        printf("%d ", wek[i]);
    }
    return 0;
}