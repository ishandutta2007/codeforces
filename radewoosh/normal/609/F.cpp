#include <bits/stdc++.h>
using namespace std;

int mil=1000000;

struct node
{
    int zab;
    vector <int> owa;
    int pra;
    int lew;
    node()
    {
        zab=mil;
        pra=lew=-1;
    }
};

int n, m;

long long n1=1;

long long gdz[1000007];
long long dlu[1000007];

long long poz[1000007];
long long roz[1000007];

int ile[1000007];

int zje[1000007];

int l=1;
node tr[17000007];

long long przy;

vector <int> lista;

int mini;

bool mniej(int a, int b)
{
    return gdz[a]<gdz[b];
}

void piszz(int v, long long a, long long b, long long graa, long long grab, int num)
{
    if (a>=graa && b<=grab)
    {
        while(!tr[v].owa.empty())
        {
            if (zje[tr[v].owa.back()])
            {
                tr[v].owa.pop_back();
                continue;
            }
            zje[tr[v].owa.back()]=1;
            przy+=roz[tr[v].owa.back()];
            ile[num]++;
            tr[v].owa.pop_back();
        }
        if (tr[v].zab==mil || gdz[tr[v].zab]>gdz[num])
        tr[v].zab=num;
        return;
    }
    if (a>grab || b<graa)
    {
        return;
    }
    if (tr[v].lew==-1)
    {
        l++;
        tr[v].lew=l-1;
    }
    if (tr[v].pra==-1)
    {
        l++;
        tr[v].pra=l-1;
    }
    piszz(tr[v].lew, a, (a+b)>>1, graa, grab, num);
    piszz(tr[v].pra, (a+b+2)>>1, b, graa, grab, num);
}

void piszmos(int v, long long a, long long b, long long cel, int num)
{
    if (a==cel && b==cel)
    {
        if (mini==mil || (tr[v].zab!=mil && gdz[tr[v].zab]<gdz[mini]))
        mini=tr[v].zab;
        tr[v].owa.push_back(num);
        return;
    }
    if (a>cel || b<cel)
    {
        return;
    }
    if (mini==mil || (tr[v].zab!=mil && gdz[tr[v].zab]<gdz[mini]))
    mini=tr[v].zab;
    tr[v].owa.push_back(num);
    if (tr[v].lew==-1)
    {
        l++;
        tr[v].lew=l-1;
    }
    if (tr[v].pra==-1)
    {
        l++;
        tr[v].pra=l-1;
    }
    piszmos(tr[v].lew, a, (a+b)>>1, cel, num);
    piszmos(tr[v].pra, (a+b+2)>>1, b, cel, num);
}

int main()
{
    scanf("%d%d", &n, &m);

    while(n1<1000000001)
    n1<<=1;

    for (int i=1; i<=n; i++)
    {
        scanf("%lld%lld", &gdz[i], &dlu[i]);
        gdz[i]++;
    }
    for (int i=1; i<=m; i++)
    {
        scanf("%lld%lld", &poz[i], &roz[i]);
        poz[i]++;
    }
    for (int i=1; i<=n; i++)
    {
        piszz(0, 1, n1, gdz[i], gdz[i]+dlu[i], i);
    }
    for (int i=1; i<=m; i++)
    {
        mini=mil;
        piszmos(0, 1, n1, poz[i], i);
        if (mini==mil)
        continue;
        przy=1;
        while(przy)
        {
            przy=0;
            piszz(0, 1, n1, gdz[mini], gdz[mini]+dlu[mini], mini);
            dlu[mini]+=przy;
        }
    }
    for (int i=1; i<=n; i++)
    {
        printf("%d %lld\n", ile[i], dlu[i]);
    }
    return 0;
}