#include <bits/stdc++.h>
using namespace std;

long long n, d;

int m;

long long poz[1000007];
long long kosz[1000007];

long long wyn;

int ost;

long long iletu[1000007];

deque <int> kolprz, kolkosz;

long long x;

long long sta;

pair <long long,long long> sor[1000007];

int main()
{
    scanf("%lld%lld%d", &d, &n, &m);
    for (int i=1; i<=m; i++)
    {
        scanf("%lld%lld", &poz[i], &kosz[i]);
        sor[i]=make_pair(poz[i], kosz[i]);
    }
    sort(sor+1, sor+1+m);
    for (int i=1; i<=m; i++)
    {
        poz[i]=sor[i].first;
        kosz[i]=sor[i].second;
    }
    poz[m+1]=d;
    for (int i=0; i<=m; i++)
    {
        if (poz[i+1]-poz[i]>n)
        {
            printf("-1\n");
            return 0;
        }
    }

    sta=n;

    for (int i=1; i<=m; i++)
    {
        iletu[i]=-poz[i];
        while(!kolprz.empty() && iletu[i]>=iletu[kolprz.back()])
        kolprz.pop_back();
        kolprz.push_back(i);
        while(!kolkosz.empty() && kosz[i]<=kosz[kolkosz.back()])
        kolkosz.pop_back();
        kolkosz.push_back(i);
        //printf("w %d mam %lld\n", i, iletu[i]+sta);
        while(sta<poz[i+1])
        {
            while(!kolprz.empty() && iletu[kolprz.front()]+sta>=n)
            {
                ost=kolprz.front();
                //printf("o %d\n", kolprz.front());
                kolprz.pop_front();
            }
            while(!kolkosz.empty() && kolkosz.front()<=ost)
            {
                kolkosz.pop_front();
            }
            x=min(poz[i+1]-sta, n-(sta+iletu[kolprz.front()]));
            //printf("dodaje %lld z %d    a bloczy %d     %lld %lld    %d\n", x, kolkosz.front(), kolprz.front(), sta, iletu[kolprz.front()], ost);
            sta+=x;
            wyn+=x*kosz[kolkosz.front()];
        }
    }
    printf("%lld\n", wyn);
    return 0;
}