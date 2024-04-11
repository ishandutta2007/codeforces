#include <bits/stdc++.h>

using namespace std;
int nzd(int a,int b)
{
    int m = max(a,b);
    int n = min(a,b);
    int r=1;
    while(r!=0)
    {
        r=m%n;
        m=n;
        n=r;
    }
    return m;
}
int main()
{
    int n=100005,m=100005;
    scanf("%i %i",&n,&m);
    if(m<n-1)
    {
        printf("Impossible\n");
        return 0;
    }
    vector<pair<int,int> > parovi;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(nzd(i,j)==1)
            {
                parovi.push_back(make_pair(i,j));
            }
            if(parovi.size()==m)
            {
                break;
            }
        }
        if(parovi.size()==m)
        {
            break;
        }
    }
    if(parovi.size()==m)
    {
        printf("Possible\n");
        for(int i=0;i<parovi.size();i++)
        {
            printf("%i %i\n",parovi[i].first,parovi[i].second);
        }
        return 0;
    }
    printf("Impossible\n");
    /*int N=100005;
    for(int i=2;i<N;i++)
    {
        printf("Graf sa %i, tacaka: ",i);
        int broj=i-1;
        for(int j=2;j<=i;j++)
        {
            for(int k=j+1;k<=i;k++)
            {
                if(nzd(j,k)==1)
                {
                    //printf(" *%i %i* ",j,k);
                    broj++;
                }
            }
        }
        printf("%i\n",broj);
    }*/
    return 0;
}