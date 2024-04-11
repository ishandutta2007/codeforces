#include <bits/stdc++.h>
using namespace std;

int n=2000000;

int tab[1007];

int sito[2000007];

int ile;

vector <int> ter;

vector <int> opty;
int optyj;

int czy;

void rek(int v)
{
    czy=1;
    for (int i=0; i<ter.size(); i++)
    {
        if (sito[ter[i]+1])
        {
            czy=0;
        }
    }
    if (ter.size()+czy*ile>opty.size()+optyj)
    {
        opty=ter;
        optyj=czy*ile;
    }
    if (v==n+1 || ter.size()==2)
    return;
    rek(v+1);
    czy=1;
    for (int i=0; i<ter.size(); i++)
    {
        if (sito[ter[i]+tab[v]])
        {
            czy=0;
        }
    }
    if (czy)
    {
        ter.push_back(tab[v]);
        rek(v+1);
        ter.pop_back();
    }
}

int main()
{
    for (int i=2; i<=n; i++)
    {
        if (!sito[i])
        {
            for (int j=i*2; j<=n; j+=i)
            {
                sito[j]=1;
            }
        }
    }
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i]);
    }
    sort(tab+1, tab+1+n);
    reverse(tab+1, tab+1+n);
    while(n && tab[n]==1)
    {
        ile++;
        n--;
    }
    rek(1);
    printf("%d\n", (int)opty.size()+optyj);
    for (int i=0; i<opty.size(); i++)
    printf("%d ", opty[i]);
    for (int i=1; i<=optyj; i++)
    printf("1 ");
    printf("\n");
    return 0;
}