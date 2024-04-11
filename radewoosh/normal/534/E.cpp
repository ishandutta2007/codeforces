#include <cstdio>
#include <map>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

int n;

long long odl[200007];
int poczm;
int m;
int pom;
int ile[200007];
int pile[200007];
long long suma;

pair <int,int> stan;

vector <long long> wyny;

pair <int,int> nast()
{
    if (stan.first==1)
    {
        return make_pair(2, 1);
    }
    if (stan.first==n)
    {
        return make_pair(n-1, -1);
    }
    return make_pair(stan.first+stan.second, stan.second);
}

pair <int,int> pop()
{
    if (stan.first==1)
    {
        return make_pair(2, -1);
    }
    if (stan.first==n)
    {
        return make_pair(n-1, 1);
    }
    return make_pair(stan.first-stan.second, stan.second);
}

long long licz(int a, int b)
{
    return odl[max(a, b)]-odl[min(a, b)];
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &odl[i]);
    }
    scanf("%d", &m);
    poczm=m;
    for (int i=1; i<=m; i++)
    {
        scanf("%d", &pom);
        ile[pom]++;
        pile[pom]++;
    }
    stan=make_pair(0, 1);
    for (int i=1; i<=n; i++)
    {
        if (!ile[nast().first])
        {
            if (m==poczm)
            {
                stan=make_pair(i, 1);
            }
            else
            {
                ile[i]++;
                suma-=licz(i, i-1);
                m++;
            }
            continue;
        }
        //printf("%d %lld\n", i, suma);
        while(ile[nast().first])
        {
            suma+=licz(stan.first, nast().first);
            stan=nast();
            ile[stan.first]--;
            m--;
        }
        if (!m)
        {
            //printf("%d %lld\n", i, suma-licz(i, i-1));
            //printf("%d %d\n\n", stan.first, stan.second);
            wyny.push_back(suma-licz(i, i-1));
        }
        ile[i]++;
        suma-=licz(i, i-1);
        m++;
    }
    m=poczm;
    suma=0;
    for (int i=1; i<=n; i++)
    {
        ile[i]=pile[i];
    }
    stan=make_pair(n+1, -1);
    for (int i=n; i; i--)
    {
        if (!ile[nast().first])
        {
            if (m==poczm)
            {
                stan=make_pair(i, -1);
            }
            else
            {
                ile[i]++;
                suma-=licz(i, i+1);
                m++;
            }
            continue;
        }
        while(ile[nast().first])
        {
            suma+=licz(stan.first, nast().first);
            stan=nast();
            ile[stan.first]--;
            m--;
        }
        if (!m)
        {
            //printf("p%d %lld\n", i, suma-licz(i, i-1));
            //printf("%d %d\n\n", stan.first, stan.second);
            wyny.push_back(suma-licz(i, i+1));
        }
        ile[i]++;
        suma-=licz(i, i+1);
        m++;
    }
    sort(wyny.begin(), wyny.end());
    if (wyny[0]!=wyny.back())
    {
        printf("-1");
        return 0;
    }
    else
    {
        printf("%lld", wyny[0]);
    }
    return 0;
}