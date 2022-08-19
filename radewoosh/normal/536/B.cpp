#include <cstdio>
using namespace std;

int n, m;

int l;
char tab[1000007];
int kmp[1000007];
int it;

int war[1000007];
int presuf[1000007];
int licz[1000007];

long long wyn=1;
long long mod=1000000007;

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s", tab);
    for (int i=1; 1; i++)
    {
        if (!tab[i])
        {
            l=i;
            break;
        }
    }
    for (int i=l; i; i--)
    {
        tab[i]=tab[i-1];
    }
    tab[0]=0;
    for (int i=2; i<=l; i++)
    {
        it=kmp[i-1];
        while(it && tab[i]!=tab[it+1])
        {
            it=kmp[it];
        }
        if (tab[i]==tab[it+1])
        {
            kmp[i]=it+1;
        }
    }
    while(kmp[l])
    {
        presuf[kmp[l]]=1;
        kmp[l]=kmp[kmp[l]];
    }
    for (int i=1; i<=m; i++)
    {
        scanf("%d", &war[i]);
        if (i==1 || war[i]>=war[i-1]+l || presuf[l-(war[i]-war[i-1])])
        {
            licz[war[i]]++;
            licz[war[i]+l]--;
            continue;
        }
        printf("0");
        return 0;
    }
    for (int i=1; i<=n; i++)
    {
        licz[i]+=licz[i-1];
        if (!licz[i])
        {
            wyn*=26;
            wyn%=mod;
        }
    }
    printf("%lld", wyn);
    return 0;
}