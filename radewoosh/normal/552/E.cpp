#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

char wcz[100007];

int pie, dru;
unsigned long long wyn;

vector <int> zac, kon;

unsigned long long w;
unsigned long long sta;

unsigned long long og;

unsigned long long licz()
{
    w=0;
    sta=1;
    for (int i=pie+2; i<=dru; i+=2)
    {
        if (i>=dru || wcz[i]=='+')
        {
            w+=(wcz[i-1]-'0')*sta;
            sta=1;
        }
        else
        {
            sta*=(wcz[i-1]-'0');
        }
    }
    if (pie==-1 && dru==n)
    return w;
    //printf(" %lld\n", w);
    og=0;
    sta=1;
    for (int i=1; i<=n; i+=2)
    {
        if (i-2==pie)
        {
            sta*=w;
            i=dru;
            continue;
        }
        if (i>=n || wcz[i]=='+')
        {
            og+=(wcz[i-1]-'0')*sta;
            sta=1;
        }
        else
        {
            sta*=(wcz[i-1]-'0');
        }
        //printf("   %lld %lld\n", og, sta);
    }
    //printf("%lld\n", og);
    return og;
}

int main()
{
    scanf("%s", wcz);
    zac.push_back(-1);
    for (int i=0; 1; i++)
    {
        if (!wcz[i])
        {
            n=i;
            break;
        }
        if (wcz[i]=='*')
        {
            zac.push_back(i);
        }
    }
    zac.push_back(n);
    wcz[n]='*';
    wcz[n+1]='1';
    n+=2;
    for (int i=0; i<zac.size(); i++)
    {
        for (int j=i+1; j<zac.size(); j++)
        {
            pie=zac[i];
            dru=zac[j];
            //printf("%d %d\n", pie, dru);
            wyn=max(wyn,licz());
        }
    }
    cout << wyn;
    return 0;
}