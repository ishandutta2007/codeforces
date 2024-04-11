#include <bits/stdc++.h>
using namespace std;

int n;

pair <int,int> tab[107];
int nal[107];
int tu[107];
int nap[107];

vector <int> wek;

int m;
int pun[307];

int wyn;

int lewo[107][107][307];

int dp[107][307];

int naj;

int inf=1000000000;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d%d", &tab[i].first, &tab[i].second);
        wek.push_back(tab[i].first-tab[i].second);
        wek.push_back(tab[i].first);
        wek.push_back(tab[i].first+tab[i].second);
    }
    sort(tab+1, tab+1+n);
    sort(wek.begin(), wek.end());

    for (int i=0; i<wek.size(); i++)
    {
        if (!i || wek[i]!=wek[i-1])
        {
            m++;
            pun[m]=wek[i];
        }
    }

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (tab[i].first-tab[i].second==pun[j])
            nal[i]=j;
            if (tab[i].first==pun[j])
            tu[i]=j;
            if (tab[i].first+tab[i].second==pun[j])
            nap[i]=j;
        }
    }

    for (int j=0; j<=n; j++)
    {
        for (int i=n; i>=0; i--)
        {
            for (int l=1; l<=m; l++)
            {
                lewo[i][j][l]=l;
                if (j<i || !(i*j))
                continue;

                naj=l;

                for (int k=j; k>=i; k--)
                {
                    if (nap[k]>=l)
                    {
                        lewo[i][j][l]=min(lewo[i][j][l], lewo[i][k-1][min(naj, tu[k])]);
                    }
                    naj=min(naj, nal[k]);
                    if (tu[k]>=l)
                    {
                        lewo[i][j][l]=min(lewo[i][j][l], lewo[i][k-1][naj]);
                    }
                }
            }
        }
    }

    for (int i=0; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            for (int l=i+1; l<=n; l++)
            {
                for (int k=j; k<=m; k++)
                {
                    dp[l][k]=max(dp[l][k], dp[i][j]+pun[k]-max(pun[j], pun[lewo[i+1][l][k]]));
                }
            }
            wyn=max(wyn, dp[i][j]);
        }
    }

    printf("%d\n", wyn);
    return 0;
}