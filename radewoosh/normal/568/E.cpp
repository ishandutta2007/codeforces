#include <bits/stdc++.h>
using namespace std;

int n;
int tab[100007];

int m;
int dod[100007];

int najm[100007];
int gdz[1000007];

int poprz[100007];
int dlutu[100007];

int wyn[100007];

int juz[100007];

int ost=1000000007;
int v;

int dlu;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    scanf("%d", &tab[i]);
    scanf("%d", &m);
    for (int i=1; i<=m; i++)
    scanf("%d", &dod[i]);
    sort(dod+1, dod+1+m);

    for (int i=1; i<=n+2; i++)
    najm[i]=1000000007;

    for (int i=1; i<=n; i++)
    {
        if (tab[i]>0)
        {
            int x=lower_bound(najm, najm+1+n, tab[i])-najm;
            najm[x]=tab[i];
            gdz[x]=i;

            dlutu[i]=x;
            poprz[i]=gdz[x-1];

        }
        else
        {
            int it=m;
            for (int j=n; j>=0; j--)
            {
                while(it>1 && dod[it-1]>najm[j])
                it--;
                if (dod[it]<=najm[j] || dod[it]>najm[j+1])
                continue;
                najm[j+1]=dod[it];
                gdz[j+1]=i;
            }
        }
    }
    for (int i=n; i; i--)
    {
        if (najm[i]<=1000000000)
        {
            v=gdz[i];
            dlu=i;
            break;
        }
    }
    for (int h=dlu; h; h--)
    {
        if (tab[v]==-1)
        {
            for (int i=m; i; i--)
            {
                if (dod[i]<ost)
                {
                    wyn[v]=dod[i];
                    juz[i]=1;
                    ost=dod[i];
                    break;
                }
            }
            if (h==1)
            break;
            for (int j=1; j<=v; j++)
            {
                if (j==v)
                {
                    for (int l=j-1; 1; l--)
                    {
                        if (tab[l]==-1)
                        {
                            v=l;
                            break;
                        }
                    }
                    break;
                }
                if (tab[j]<ost && dlutu[j]==h-1)
                {
                    v=j;
                    break;
                }
            }
        }
        else
        {
            ost=tab[v];
            v=poprz[v];
        }
    }
    int it=1;
    for (int i=1; i<=n; i++)
    {
        if (!wyn[i])
        {
            if (tab[i]>0)
            {
                wyn[i]=tab[i];
            }
            else
            {
                while(juz[it])
                it++;
                wyn[i]=dod[it];
                it++;
            }
        }
        printf("%d ", wyn[i]);
    }
    printf("\n");
    return 0;
}