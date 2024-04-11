#include <bits/stdc++.h>
using namespace std;

int n;

pair <long long,long long> tab[1000007];

pair <long long,long long> wyn;
pair <long long,long long> kan;
pair <int,int> odp;

long long inf;

vector <int> jed;
vector <int> dwa;

vector <int> cal;

long long ilo(int a, int b)
{
    return tab[a].first*tab[b].second-tab[b].first*tab[a].second;
}

long long ilos(int a, int b)
{
    return tab[a].first*tab[b].first+tab[a].second*tab[b].second;
}

bool mniej(int a, int b)
{
    return ilo(a, b)>0;
}

long long dlu(int a)
{
    return tab[a].first*tab[a].first+tab[a].second*tab[a].second;
}

long long sta=1000000000;

long long wi[42], we[42];
vector <long long> ro, ri;

int por(pair <long long,long long> a, pair <long long,long long> b)
{
    if (a.first<0 && b.first>=0)
    return 1;
    if (a.first>=0 && b.first<0)
    return 0;
    if (a.first<0 && b.first<0)
    {
        swap(a, b);
        a.first*=-1;
        b.first*=-1;
    }
    for (int i=0; i<=20; i++)
    {
        wi[i]=0;
        we[i]=0;
    }
    ro.clear();
    ri.clear();
    while(a.first)
    {
        ri.push_back(a.first%1000);
        a.first/=1000;
    }
    while(b.second)
    {
        ro.push_back(b.second%1000);
        b.second/=1000;
    }
    for (int i=0; i<ri.size(); i++)
    {
        for (int j=0; j<ro.size(); j++)
        {
            wi[i+j]+=ri[i]*ro[j];
        }
    }
    for (int i=0; i<=15; i++)
    {
        wi[i+1]+=wi[i]/1000;
        wi[i]%=1000;
    }
    ro.clear();
    ri.clear();
    while(b.first)
    {
        ri.push_back(b.first%1000);
        b.first/=1000;
    }
    while(a.second)
    {
        ro.push_back(a.second%1000);
        a.second/=1000;
    }
    for (int i=0; i<ri.size(); i++)
    {
        for (int j=0; j<ro.size(); j++)
        {
            we[i+j]+=ri[i]*ro[j];
        }
    }
    for (int i=0; i<=15; i++)
    {
        we[i+1]+=we[i]/1000;
        we[i]%=1000;
    }
    for (int i=15; i>=0; i--)
    {
        if (we[i]!=wi[i])
        {
            return wi[i]<we[i];
        }
    }
    return 1;
}

int main()
{
    inf=1000000000;
    inf*=inf;
    wyn=make_pair(inf, 1);
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld%lld", &tab[i].first, &tab[i].second);
        if (tab[i].first>0 || ( tab[i].first==0 && tab[i].second>0 ) )
        {
            jed.push_back(i);
        }
        else
        {
            dwa.push_back(i);
        }
    }
    if (n==2)
    {
        printf("1 2\n");
        return 0;
    }
    sort(jed.begin(), jed.end(), mniej);
    sort(dwa.begin(), dwa.end(), mniej);
    for (int i=0; i<jed.size(); i++)
    {
        cal.push_back(jed[i]);
    }
    for (int i=0; i<dwa.size(); i++)
    {
        cal.push_back(dwa[i]);
    }
    cal.push_back(cal[0]);
    for (int i=1; i<cal.size(); i++)
    {
        kan=make_pair(ilos(cal[i], cal[i-1])*ilos(cal[i], cal[i-1]), dlu(cal[i])*dlu(cal[i-1]));
        if (ilos(cal[i], cal[i-1])<0)
        kan.first*=-1;
        //printf("%lld %lld    %lld %lld    %d %d\n", kan.first, kan.second, wyn.first, wyn.second, cal[i], cal[i-1]);
        if (ilo(cal[i], cal[i-1]) && ( odp==make_pair(0, 0) || !por(kan, wyn) ) )
        {
            wyn=kan;
            odp=make_pair(cal[i], cal[i-1]);
        }
    }
    printf("%d %d\n", odp.first, odp.second);
    return 0;
}