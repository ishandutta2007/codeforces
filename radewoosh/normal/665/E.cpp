#include <bits/stdc++.h>
using namespace std;

int n, k;

int tab[1000007];

int l;

int dzie[40000007][2];
int ile[40000007];

int d=32;

int p1, p2;

vector <int> vv;
vector <int> kk;

long long wyn;

void daj(int v)
{
    vv.clear();
    for (int i=1; i<=d; i++)
    {
        vv.push_back(v&1);
        v>>=1;
    }
    reverse(vv.begin(), vv.end());
}

void wrzu(int v)
{
    daj(v);
    vector <int> scie;
    scie.push_back(0);
    for (int i=0; i<d; i++)
    {
        if (!dzie[scie.back()][vv[i]])
        {
            l++;
            dzie[scie.back()][vv[i]]=l;
        }
        p1=dzie[scie.back()][vv[i]];
        scie.push_back(p1);
    }
    for (int i=0; i<scie.size(); i++)
    {
        ile[scie[i]]++;
    }
}

inline void dod(int v)
{
    if (v)
    wyn+=ile[v];
}

void rob(int v)
{
    daj(v);
    int u=0;
    for (int i=0; i<d; i++)
    {
        if (kk[i])
        {
            if (!dzie[u][vv[i]^1])
            {
                l++;
                dzie[u][vv[i]^1]=l;
            }
            u=dzie[u][vv[i]^1];
        }
        else
        {
            dod(dzie[u][vv[i]^1]);
            if (!dzie[u][vv[i]])
            {
                l++;
                dzie[u][vv[i]]=l;
            }
            u=dzie[u][vv[i]];
        }
    }
    dod(u);
}

int main()
{
    scanf("%d%d", &n, &k);
    daj(k);
    kk=vv;
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i]);
    }
    for (int i=1; i<=n; i++)
    {
        tab[i]^=tab[i-1];
    }
    for (int i=1; i<=n; i++)
    {
        wrzu(tab[i-1]);
        rob(tab[i]);
    }
    printf("%lld\n", wyn);
    return 0;
}