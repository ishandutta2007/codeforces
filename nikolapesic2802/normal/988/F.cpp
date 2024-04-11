#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int> > intervali,kisobrani;
const int N=2010;
bool ima_kise[N];
int zadnji[N];
int a,n,m;
int dp[N][N];
int min_dp(int stigao,int nosim)
{
    //printf("Usao za %i %i    %i  %i\n",stigao,nosim,kisobrani[stigao].first,kisobrani[stigao].second);
    if(kisobrani[stigao].first==a&&kisobrani[stigao].second==-1)
    {
        return 0;
    }
    if(dp[stigao][nosim]!=-2)
    {
        return dp[stigao][nosim];
    }
    int minn=(kisobrani[stigao+1].first-kisobrani[stigao].first)*kisobrani[stigao].second+min_dp(stigao+1,stigao);
    if(nosim!=-1)
    {
        minn=min(minn,(kisobrani[stigao+1].first-kisobrani[stigao].first)*kisobrani[nosim].second+min_dp(stigao+1,nosim));
    }
    if(!ima_kise[stigao])
    {
        minn=min(minn,min_dp(stigao+1,-1));
    }
    if(ima_kise[stigao])
    {
        if(zadnji[stigao]!=-1)
        {
            minn=min(minn,(zadnji[stigao]-kisobrani[stigao].first)*kisobrani[stigao].second+min_dp(stigao+1,-1));
            if(nosim!=-1)
            {
                minn=min(minn,(zadnji[stigao]-kisobrani[stigao].first)*kisobrani[nosim].second+min_dp(stigao+1,-1));
            }
        }
    }
    dp[stigao][nosim]=minn;
    return minn;
}
int main()
{
    for(int i=0;i<N;i++)
    {
        zadnji[i]=-1;
        for(int j=-1;j<N;j++)
        {
            dp[i][j]=-2;
        }
    }
    scanf("%i %i %i",&a,&n,&m);
    for(int i=0;i<n;i++)
    {
        int c,d;
        scanf("%i %i",&c,&d);
        intervali.push_back(make_pair(c,d));
    }
    intervali.push_back(make_pair(3000,3000));
    intervali.push_back(make_pair(-1,-1));
    sort(intervali.begin(),intervali.end());
    for(int i=0;i<m;i++)
    {
        ima_kise[i]=false;
        int c,d;
        scanf("%i %i",&c,&d);
        kisobrani.push_back(make_pair(c,d));
    }
    ima_kise[m]=false;
    kisobrani.push_back(make_pair(a,-1));
    sort(kisobrani.begin(),kisobrani.end());
    if(intervali[1].first<kisobrani[0].first)
    {
        printf("-1\n");
        return 0;
    }
    int pi=1,pk=0;
    while(kisobrani[pk].first!=a||kisobrani[pk].second!=-1)
    {
       //printf("%i %i   %i-%i   %i, %i\n",pi,pk,intervali[pi].first,intervali[pi].second,kisobrani[pk].first,kisobrani[pk].second);
        bool test=false;
        if(intervali[pi-1].second>kisobrani[pk].first)
        {
            //printf("1\n");
            test=true;
        }
        while(intervali[pi].first<kisobrani[pk+1].first)
        {
            //printf("2\n");
            test=true;
            pi++;
        }
        if(intervali[pi-1].second<=kisobrani[pk+1].first)
        {
            //printf("4\n");
            zadnji[pk]=intervali[pi-1].second;
        }
        if(intervali[pi].first==kisobrani[pk+1].first)
        {
            //printf("3\n");
            pi++;
        }
        ima_kise[pk]=test;
        pk++;
    }
    /*for(int i=0;i<m+1;i++)
    {
        printf("%i %i: %i  %i\n",kisobrani[i].first,kisobrani[i].second,ima_kise[i],zadnji[i]);
    }*/
    printf("%i\n",min_dp(0,-1));
    return 0;
}