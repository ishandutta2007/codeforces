#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
int dev(int x,int y)
{
    int res=x/y;
    if(x%y!=0)
        res++;
    return res;
}
int main()
{
    int n,x1,x2;
    scanf("%i %i %i",&n,&x1,&x2);
    vector<pair<int,int> > niz(n);
    for(int i=0; i<n; i++)
    {
        scanf("%i",&niz[i].first);
        niz[i].second=i+1;
    }
    sort(niz.begin(),niz.end());
    reverse(niz.begin(),niz.end());
    set<pair<int,int> > veci;
    for(int i=0; i<n; i++)
    {
        veci.insert({niz[i].first,n-i});
    }
    int minn=-1;
    for(int i=0; i<n; i++)
    {
        if(dev(x1,i+1)<=niz[i].first)
        {
            minn=i+1;
            //printf("Mogu da predstavim %i sa %i\n",x1,i+1);
            break;
        }
    }
    if(minn==-1)
    {
        printf("No\n");
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        int k=dev(x2,i);
        int treba=minn+i-1;
        pair<int,int> tr;
        if(veci.lower_bound({k,0})==veci.end())
            continue;
        tr=*veci.lower_bound({k,0});
        if(n-tr.second>=treba)
        {
            printf("Yes\n");
            printf("%i %i\n",minn,i);
            for(int j=0; j<minn; j++)
            {
                printf("%i ",niz[j].second);
            }
            printf("\n");
            for(int j=0; j<i; j++)
            {
                printf("%i ",niz[n-tr.second-j].second);
            }
            return 0;
        }
    }
    swap(x1,x2);
    minn=-1;
    for(int i=0; i<n; i++)
    {
        if(dev(x1,i+1)<=niz[i].first)
        {
            minn=i+1;
            //printf("Mogu da predstavim %i sa %i\n",x1,i+1);
            break;
        }
    }
    if(minn==-1)
    {
        printf("No\n");
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        int k=dev(x2,i);
        //printf("Gledam za %i\n",k);
        int treba=minn+i-1;
        pair<int,int> tr;
        if(veci.lower_bound({k,0})==veci.end())
            continue;
        tr=*veci.lower_bound({k,0});
        //printf("nasao %i %i\n",tr.first,n-tr.second);
        if(n-tr.second>=treba)
        {
            //printf("Nasao za %i od %i\n",i,tr.first);
            printf("Yes\n");
            printf("%i %i\n",i,minn);
            for(int j=0; j<i; j++)
            {
                printf("%i ",niz[n-tr.second-j].second);
            }
            printf("\n");
            for(int j=0; j<minn; j++)
            {
                printf("%i ",niz[j].second);
            }
            return 0;
        }
    }
    printf("No\n");
    return 0;
}