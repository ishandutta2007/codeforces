#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct ule
{
    int typ;
    int roz;
    int num;
    long long licz;
    long long mia;
    ule()
    {
        licz=num=roz=0;
        mia=1;
    }
};

bool operator < (ule a, ule b)
{
    return ((long double) a.licz)/a.mia < ((long double) b.licz)/b.mia;
}

int k;
int n, m;

long long tab[100007];

ule dop;

ule row[100007];
vector < ule > mno;
vector < ule > dod;

int p1;
int p2;
long long p3;

vector < ule > wyn;

bool mniej(ule a, ule b)
{
    if (a.typ==b.typ)
    return a.roz<b.roz;
    return a.typ<b.typ;
}

int main()
{
    scanf("%d%d%d", &k, &n, &m);
    for (int i=1; i<=k; i++)
    {
        scanf("%lld", &tab[i]);
    }
    for (int i=1; i<=n; i++)
    {
        scanf("%d%d%lld", &p1, &p2, &p3);
        dop.typ=p1;
        dop.roz=i;
        dop.num=p2;
        dop.licz=p3;
        dop.mia=1;
        if (p1==1)
        {
            row[p2]=max(row[p2], dop);
        }
        if (p1==2)
        {
            dod.push_back(dop);
        }
        if (p1==3)
        {
            mno.push_back(dop);
        }
    }
    for (int i=1; i<=k; i++)
    {
        if (row[i].licz>tab[i])
        {
            dop.typ=row[i].typ;
            dop.roz=row[i].roz;
            dop.num=row[i].num;
            dop.licz=row[i].licz-tab[i];
            dop.mia=1;
            dod.push_back(dop);
        }
    }
    sort(dod.begin(), dod.end());
    while(!dod.empty())
    {
        dop.typ=dod.back().typ;
        dop.roz=dod.back().roz;
        dop.num=dod.back().num;
        dop.mia=tab[dod.back().num];
        dop.licz=tab[dod.back().num]+dod.back().licz;
        mno.push_back(dop);
        tab[dod.back().num]=dop.licz;
        dod.pop_back();
    }
    sort(mno.begin(), mno.end());
    reverse(mno.begin(), mno.end());
    for (int i=0; i<mno.size() && i<m; i++)
    {
        wyn.push_back(mno[i]);
    }
    sort(wyn.begin(), wyn.end(), mniej);
    printf("%d\n", wyn.size());
    for (int i=0; i<wyn.size(); i++)
    {
        printf("%d ", wyn[i].roz);
    }
    return 0;
}