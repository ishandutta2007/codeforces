#include <bits/stdc++.h>
using namespace std;

int n, m;

char tab[507][507];
int odl[507][507];

int mod=1000000007;

int dps[507][507];
int dpn[507][507];

vector < pair <int,int> > wek[1007];

int t, p;

long long wyn;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        scanf("%s", tab[i]);
        for (int j=m; j; j--)
        {
            tab[i][j]=tab[i][j-1];
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            odl[i][j]=max(odl[i-1][j], odl[i][j-1])+1;
            wek[odl[i][j]].push_back(make_pair(i, j));
        }
    }
    if (tab[1][1]!=tab[n][m])
    {
        printf("0");
        return 0;
    }
    dpn[0][0]=1;
    for (int i=2; i<=(n+m)/2; i++)
    {
        t=i;
        p=n+m-i;
        for (int j=0; j<wek[t-1].size(); j++)
        {
            for (int l=0; l<wek[p+1].size(); l++)
            {
                dps[j][l]=dpn[j][l];
            }
        }
        for (int j=0; j<wek[t].size(); j++)
        {
            for (int l=0; l<wek[p].size(); l++)
            {
                dpn[j][l]=0;
            }
        }
        for (int j=0; j<wek[t].size(); j++)
        {
            for (int l=0; l<wek[p].size(); l++)
            {
                if (tab[wek[t][j].first][wek[t][j].second]!=tab[wek[p][l].first][wek[p][l].second])
                continue;
                for (int jj=j-2; jj<=j+2; jj++)
                {
                    if (jj<0 || jj>=wek[t-1].size() || (wek[t][j].first!=wek[t-1][jj].first && wek[t][j].second!=wek[t-1][jj].second))
                    continue;
                    for (int ll=l-2; ll<=l+2; ll++)
                    {
                        if (ll<0 || ll>=wek[p+1].size() || (wek[p][l].first!=wek[p+1][ll].first && wek[p][l].second!=wek[p+1][ll].second))
                        continue;
                        dpn[j][l]+=dps[jj][ll];
                        if (dpn[j][l]>=mod)
                        dpn[j][l]-=mod;
                    }
                }
            }
        }
    }
    if ((n+m)&1)
    {
        t=(n+m)/2;
        p=t+1;
        for (int i=0; i<wek[t].size(); i++)
        {
            for (int j=0; j<wek[p].size(); j++)
            {
                if (wek[t][i].first==wek[p][j].first || wek[t][i].second==wek[p][j].second)
                {
                    if (tab[wek[t][i].first][wek[t][i].second]==tab[wek[p][j].first][wek[p][j].second])
                    wyn+=dpn[i][j];
                    //printf("%d %d  %d %d   %d\n", wek[t][i].first, wek[t][i].second, wek[p][j].first, wek[p][j].second, dpn[i][j]);
                }
            }
        }
    }
    else
    {
        t=(n+m)/2;
        for (int i=0; i<wek[t].size(); i++)
        {
            wyn+=dpn[i][i];
        }
    }
    printf("%lld\n", wyn%mod);
    return 0;
}