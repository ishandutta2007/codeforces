#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char tab[1000007];
int kmrs[1000007];
int kmrn[1000007];
int m;
int l;

vector <int> sor1[1000007];
vector <int> sor2[1000007];

int sa[1000007];
int rank[1000007];
int lcp[1000007];

int dluwyn[1000007];
int it1, it2;
int kmp[1000007];
vector <pair <int,int> > wek;

int main()
{
    scanf("%s", &tab);
    for (int i=0; 1; i++)
    {
        if (!tab[i])
        {
                    n=i;
                    break;
        }
    }
    if (n==1)
    {
             printf("1\n1 1");
             return 0;
    }
    for (int i=n; i; i--)
    {
        tab[i]=tab[i-1];
    }
    tab[0]=0;
    for (int i=n+1; i<=4*n; i++)
    {
        tab[i]=0;
    }
    m=max(n,1000);
    for (int i=1; i<=n; i++)
    {
        kmrn[i]=tab[i];
    }
    for (int h=1; (1<<(h-1))<=n; h++)
    {
        for (int i=0; i<=m; i++)
        {
            kmrs[i]=kmrn[i];
            kmrn[i]=0;
            sor1[i].clear();
            sor2[i].clear();
        }
        for (int i=1; i<=n; i++)
        {
            sor1[kmrs[i+(1<<(h-1))]].push_back(i);
        }
        for (int i=0; i<=m; i++)
        {
            for (int j=0; j<sor1[i].size(); j++)
            {
                sor2[kmrs[sor1[i][j]]].push_back(sor1[i][j]);
            }
        }
        l=0;
        for (int i=0; i<=m; i++)
        {
            for (int j=0; j<sor2[i].size(); j++)
            {
                if (!j || kmrs[sor2[i][j]+(1<<(h-1))]!=kmrs[sor2[i][j-1]+(1<<(h-1))])
                {
                       l++;
                }
                kmrn[sor2[i][j]]=l;
            }
        }
    }
    for (int i=1; i<=n; i++)
    {
        rank[i]=kmrn[i];
    }
    for (int i=1; i<=n; i++)
    {
        sa[rank[i]]=i;
    }
    l=0;
    for (int i=1; i<=n; i++)
    {
        if (rank[i]==1)
        {
                       l=max(l-1, 0);
                       continue;
        }
        //printf("%d %d\n", i, sa[rank[i]-1]);
        while(tab[i+l]==tab[sa[rank[i]-1]+l])
        l++;
        lcp[rank[i]-1]=l;
        l=max(l-1, 0);
    }
    /*for (int i=1; i<=n; i++)
    {
        printf("%d ", sa[i]);
    }
    printf("\n");
    for (int i=1; i<=n; i++)
    {
        printf("%d ", rank[i]);
    }
    printf("\n");
    for (int i=1; i<=n; i++)
    {
        printf("%d ", lcp[i]);
    }
    printf("\n");*/
    it1=it2=rank[1];
    for (int i=n; i; i--)
    {
        while(it1<=n && lcp[it1]>=i)
        {
                          it1++;
        }
        while(it2>1 && lcp[it2-1]>=i)
        {
                          it2--;
        }
        dluwyn[i]=it1-it2+1;
        //printf("%d    %d %d\n", i, it2, it1);
    }
    for (int i=2; i<=n; i++)
    {
        l=kmp[i-1];
        while(l && tab[i]!=tab[l+1])
        l=kmp[l];
        //printf("%c %c  %d %d\n",tab[i], tab[l+1], i, l+1);
        if (tab[i]==tab[l+1])
        kmp[i]=l+1;
        //printf("%d\n",kmp[i]);
    }
    wek.push_back(make_pair(n, 1));
    while(kmp[n])
    {
                 wek.push_back(make_pair(kmp[n], dluwyn[kmp[n]]));
                 kmp[n]=kmp[kmp[n]];
    }
    sort(wek.begin(), wek.end());
    printf("%d\n", wek.size());
    for (int i=0; i<wek.size(); i++)
    {
        printf("%d %d\n", wek[i].first, wek[i].second);
    }
    //system("pause");
    return 0;
}