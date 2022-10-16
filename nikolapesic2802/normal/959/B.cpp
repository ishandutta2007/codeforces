#include <bits/stdc++.h>

using namespace std;
map<string,int> mapa;
int main()
{
    int n,k,m;
    scanf("%i %i %i ",&n,&k,&m);
    string words[n+1];
    char rec[21];
    for(int i=0;i<n;i++)
    {
        scanf("%s",rec);
        words[i]=rec;
        /*for(int j=0;j<words[i].size();j++)
        {
            printf("%c",words[i][j]);
        }
        printf("\n***-%i\n",words[i].size());*/
    }
    int costs[n+1];
    for(int i=0;i<n;i++)
    {
        scanf("%i",&costs[i]);
        //printf("%i\n",costs[i]);
    }
    for(int i=0;i<k;i++)
    {
        int x;
        scanf("%i",&x);
        int grupa[x+1];
        int minn=0;
        for(int j=0;j<x;j++)
        {
            scanf("%i",&grupa[j]);
            if(minn==0||minn>costs[grupa[j]-1])
            {
                minn=costs[grupa[j]-1];
            }
        }
        for(int j=0;j<x;j++)
        {
            mapa[words[grupa[j]-1]]=minn;
        }
    }
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<words[i].size();j++)
        {
            printf("%c",words[i][j]);
        }
        printf("\n***-%i  cena:%i\n",words[i].size(),mapa[words[i]]);
    }*/
    long long price=0;
    for(int i=0;i<m;i++)
    {
        char c[20];
        scanf("%s",c);
        price+=(long long)mapa[c];
    }
    printf("%lld",price);
    return 0;
}