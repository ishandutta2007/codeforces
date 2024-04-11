#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
map<int,vector<int> > vektor;
int sledeci[15000005];
vector<int> primes;
int main()
{
    int n;
    scanf("%i",&n);
    sledeci[1]=1;
    for(int i=2;i<=15000000;i++)
    {
        if(sledeci[i]==0)
        {
            primes.pb(i);
            int tr=2*i;
            sledeci[i]=1;
            while(tr<=15000000)
            {
                sledeci[tr]=tr/i;
                tr+=i;
            }
        }
    }



    for(int i=0;i<n;i++)
    {
        int d;
        scanf("%i",&d);
        map<int,int> mapa;
        while(d!=1)
        {
            //printf("%i %i\n",d,sledeci[d]);
            int k=d/sledeci[d];
            if(mapa[k]>=vektor[k].size())
            {
                vektor[k].pb(0);
            }
            //printf("%i %i\n",broj[k].size(),k);
            vektor[k][mapa[k]]++;
            mapa[k]++;
            d=sledeci[d];
        }
    }
    int minn=n;
    //printf("%i\n",primes.size());
    //return 0;
    for(int l=0;l<primes.size();l++)
    {
        int i=primes[l];
        //if(vektor[i].size()>0)
        //printf("Velicina od %i: %i\n",i,vektor[i].size());
        for(int j=0;j<vektor[i].size();j++)
        {
            //printf("wtf");
            if(n-vektor[i][j]>0)
            {
                minn=min(minn,n-vektor[i][j]);
            }
        }
    }
    if(minn==n)
    {
        printf("-1\n");
        return 0;
    }
    printf("%i\n",minn);
    return 0;
}