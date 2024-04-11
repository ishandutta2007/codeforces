#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

int n, m;
int tab[1000007];

int sito[1000007];
vector <int> czyn[1000007];
vector < pair <int,int> > dziel[1000007];

long long wyn;

bitset <50> bity;

int ilo;

int ile;

int x;

int wys[1000007];

int iletego[1000007];

int ilejed;
int ilenas;

int pam;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i]);
    }
    for (int i=2; i<=500000; i++)
    {
        if (!sito[i])
        {
            for (int j=i; j<=500000; j+=i)
            {
                sito[j]=i;
            }
        }
        czyn[i]=czyn[i/sito[i]];
        if (!czyn[i].size() || czyn[i].back()!=sito[i])
        {
            czyn[i].push_back(sito[i]);
        }
    }
    for (int i=2; i<=500000; i++)
    {
        for (int h=1; h<(1<<((int)czyn[i].size())); h++)
        {
            bity=h;
            ilo=1;
            ile=0;
            for (int j=0; j<czyn[i].size(); j++)
            {
                if (bity[j])
                {
                    ilo*=czyn[i][j];
                    ile++;
                }
            }
            if (ile&1)
            {
                dziel[i].push_back(make_pair(ilo,1));
            }
            else
            {
                dziel[i].push_back(make_pair(ilo,-1));
            }
        }
    }
    while(m--)
    {
        scanf("%d", &x);
        if (!wys[x])
        {
            wys[x]=1;
            x=tab[x];
            pam=0;
            if (x>1)
            {
                for (int i=0; i<dziel[x].size(); i++)
                {
                    pam+=iletego[dziel[x][i].first]*dziel[x][i].second;
                    iletego[dziel[x][i].first]++;
                }
                wyn+=ilenas-pam;
                wyn+=ilejed;
                ilenas++;
            }
            else
            {

                wyn+=ilenas+ilejed;
                ilejed++;
            }
        }
        else
        {
            wys[x]=0;
            x=tab[x];
            pam=0;
            if (x>1)
            {
                ilenas--;
                for (int i=0; i<dziel[x].size(); i++)
                {
                    iletego[dziel[x][i].first]--;
                    pam+=iletego[dziel[x][i].first]*dziel[x][i].second;
                }
                wyn-=ilenas-pam;
                wyn-=ilejed;
            }
            else
            {
                ilejed--;
                wyn-=ilenas+ilejed;
            }
        }
        printf("%lld\n", wyn);
    }
    return 0;
}