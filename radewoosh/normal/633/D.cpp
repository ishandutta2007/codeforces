#include <bits/stdc++.h>
using namespace std;

int n;

long long tab[1000007];

long long k=1000000001;

long long h=263;
long long mod=10007;

map <long long,int> mapa[10017];

int wyn=2;

vector <long long> stos;

int a, b;

inline int ile(long long v)
{
    v+=k;
    return mapa[(v*h)%mod][v];
}

inline void usu(long long v)
{
    v+=k;
    mapa[(v*h)%mod][v]--;
}

inline void dod(long long v)
{
    v+=k;
    mapa[(v*h)%mod][v]++;
}

int main()
{
    scanf("%d", &n);
    k*=3;
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
        dod(tab[i]);
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (i==j)
            continue;
            stos.push_back(tab[i]);
            stos.push_back(tab[j]);

            usu(tab[i]);
            usu(tab[j]);

            while(1)
            {
                if (stos.back()==0 && stos[stos.size()-2]==0)
                {
                    wyn=max(wyn, (int)stos.size()+ile(0));
                    break;
                }
                if (ile(stos[stos.size()-2]+stos[stos.size()-1]))
                {
                    stos.push_back(stos[stos.size()-2]+stos[stos.size()-1]);
                    usu(stos.back());
                    wyn=max(wyn, (int)stos.size());
                }
                else
                break;
            }
            wyn=max(wyn, (int)stos.size());

            while(!stos.empty())
            {
                dod(stos.back());
                stos.pop_back();
            }
        }
    }
    printf("%d\n", wyn);
    return 0;
}