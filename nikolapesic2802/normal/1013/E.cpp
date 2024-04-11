#include <bits/stdc++.h>

using namespace std;
const long long oo=9223372036854775800;
const int N=5020;
int n;
int velicina[N];
long long cost[N][N/2][2];
long long minDP(int stigao,int koliko,int poslednji)
{
    //printf("Pozvan za %i %i %i\n",stigao,koliko,poslednji);
    if(cost[stigao][koliko][poslednji]!=-1)
    {
        return cost[stigao][koliko][poslednji];
    }
    if(koliko==0)
    {
        cost[stigao][koliko][poslednji]=0;
        return 0;
    }
    if(stigao>n)
    {
        cost[stigao][koliko][poslednji]=oo;
        return oo;
    }
    long long sol=oo;
    long long sol1=minDP(stigao+2,koliko-1,1),sol2=minDP(stigao+1,koliko,0);
    //printf("%lld %lld   %i %i %i\n",sol1,sol2,stigao,koliko,poslednji);
    if(sol1!=oo)
    {
        long long cena=0;
        if(poslednji==0)
        {
            cena+=max(0,velicina[stigao-1]-velicina[stigao]+1);
            cena+=max(0,velicina[stigao+1]-velicina[stigao]+1);
        }
        else
        {
            int prosli=min(velicina[stigao-2]-1,velicina[stigao-1]);
            cena+=max(0,prosli-velicina[stigao]+1);
            cena+=max(0,velicina[stigao+1]-velicina[stigao]+1);
        }
        sol1=sol1+cena;
        sol=sol1;
    }
    //printf("%lld %lld   %i %i %i\n",sol1,sol2,stigao,koliko,poslednji);
    if(sol2!=oo)
    {
        sol=min(sol,sol2);
    }
    cost[stigao][koliko][poslednji]=sol;
    return sol;
}
int main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N/2;j++)
        {
            for(int k=0;k<2;k++)
            {
                cost[i][j][k]=-1;
            }
        }
    }
    scanf("%i",&n);
    velicina[0]=-1;
    velicina[n+1]=-1;
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&velicina[i]);
    }
    int lol=n/2;
    if(n%2==1)
    {
        lol++;
    }
    //printf("%i\n",lol);
    //printf("%lld ",minDP(1,1,0));
    for(int i=1;i<=lol;i++)
    {
        printf("%lld ",minDP(1,i,0));
    }
    return 0;
}