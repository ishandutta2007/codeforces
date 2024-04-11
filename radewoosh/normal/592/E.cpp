#include <bits/stdc++.h>
using namespace std;

int n;

long long c, d;

pair <long long,long long> tab[1000007];

long long nwd;

vector < pair < pair <long long,long long > , long long > > wek;

vector < pair < pair <long long,long long > , long long > > jed, dwa;

long long ilo(pair <long long,long long > a, pair <long long,long long > b)
{
    return a.first*b.second-a.second*b.first;
}

bool mniej(pair < pair <long long,long long > , long long > a, pair < pair <long long,long long > , long long > b)
{
    return ilo(a.first, b.first)<0;
}

int it;

long long wyn;

map < pair <long long,long long> , long long > mapa;

int main()
{
    scanf("%d", &n);
    scanf("%lld%lld", &c, &d);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld%lld", &tab[i].first, &tab[i].second);
        tab[i].first-=c;
        tab[i].second-=d;
        nwd=__gcd(abs(tab[i].first), abs(tab[i].second));
        tab[i].first/=nwd;
        tab[i].second/=nwd;
    }
    sort(tab+1, tab+1+n);
    for (int i=1; i<=n; i++)
    {
        if (i==1 || tab[i]!=tab[i-1])
        {
            wek.push_back(make_pair(tab[i], 1));
        }
        else
        {
            wek.back().second++;
        }
    }
    for (int i=0; i<wek.size(); i++)
    {
        if (wek[i].first.first>0 || (wek[i].first.first==0 && wek[i].first.second>0) )
        {
            jed.push_back(wek[i]);
        }
        else
        {
            dwa.push_back(wek[i]);
        }
    }
    sort(jed.begin(), jed.end(), mniej);
    sort(dwa.begin(), dwa.end(), mniej);
    wek.clear();
    for (int i=0; i<jed.size(); i++)
    {
        wek.push_back(jed[i]);
    }
    for (int i=0; i<dwa.size(); i++)
    {
        wek.push_back(dwa[i]);
    }
    wyn=(long long) n*(n-1)*(n-2);
    wyn/=6;
    it=1;
    c=0;
    if (wek.size()<3)
    {
        printf("0\n");
        return 0;
    }
    for (int i=0; i<wek.size(); i++)
    {
        mapa[wek[i].first]=wek[i].second;
        while(ilo(wek[i].first, wek[it].first)<=0)
        {
            if (c>2*n)
            {
                printf("0\n");
                return 0;
            }
            c+=wek[it].second;
            it=(it+1)%wek.size();
        }
        //printf("%d %d  %lld\n", i, it, c);
        for (int j=1; j<=wek[i].second; j++)
        {
            c+=j-1;
            wyn-=(c*(c-1))/2;
            c-=j-1;
        }
        c-=wek[(i+1)%wek.size()].second;
    }
    for (map < pair <long long,long long> , long long >::iterator jt=mapa.begin(); jt!=mapa.end(); jt++)
    {
        wyn+=mapa[make_pair( -(jt->first).first , -(jt->first).second )]*(jt->second)*((jt->second)-1)/2;
    }
    printf("%lld\n", wyn);
    return 0;
}