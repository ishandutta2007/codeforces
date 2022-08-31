#include <bits/stdc++.h>
using namespace std;

int n;

long long tab[1000007];

vector <int> start;

long long inf;

int x;

long long v, u;

bool mniej(int a, int b)
{
    return tab[a]<tab[b];
}

long long rek(int l, int p, vector <int> &wek)
{
    if (l==p)
    return inf;
    vector <int> jed, dwa;
    long long ret=inf;
    for (int i=0; i<wek.size(); i++)
    {
        if (wek[i]<=((l+p)>>1))
        jed.push_back(wek[i]);
        else
        dwa.push_back(wek[i]);
    }
    ret=min(ret, rek(l, (l+p)>>1, jed));
    ret=min(ret, rek((l+p+2)>>1, p, dwa));
    vector <int> fil;
    for (int i=0; i<wek.size(); i++)
    {
        v=((l+p)>>1)-wek[i];
        v*=v;
        if (ret>=v)
        {
            fil.push_back(wek[i]);
        }
    }
    x=0;
    for (int i=0; i<fil.size(); i++)
    {
        while((tab[fil[i]]-tab[fil[x]])*(tab[fil[i]]-tab[fil[x]])>=ret)
        x++;
        for (int j=x; j<i; j++)
        {
            v=fil[i]-fil[j];
            u=tab[fil[i]]-tab[fil[j]];
            ret=min(ret, v*v+u*u);
        }
    }
    return ret;
}

int main()
{
    inf=1500000000;
    inf*=inf;
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
        tab[i]+=tab[i-1];
        start.push_back(i);
    }
    sort(start.begin(), start.end(), mniej);
    printf("%lld", rek(1, n, start));
    return 0;
}