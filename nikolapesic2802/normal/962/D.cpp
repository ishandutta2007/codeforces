#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    set<pair<long long,int> > s;
    set<pair<long long,int> >::iterator it;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        s.insert(make_pair((long long)a,i));
    }
    pair<long long,int> t1,t2,t;
    long long niz[2*n+2];
    for(int i=0;i<2*n+2;i++)
    {
        niz[i]=-1;
    }
    while(s.size()>1)
    {
        it=s.begin();
        t1=*it;
        s.erase(it);
        it=s.begin();
        t2=*it;
        if(t1.first==t2.first)
        {
            s.erase(it);
            t=make_pair(t1.first*2,t2.second);
            s.insert(t);
        }
        else
        {
            niz[t1.second]=t1.first;
        }
    }
    if(s.size()==1)
    {
        it=s.begin();
        t1=*it;
        niz[t1.second]=t1.first;
    }
    int co=0;
    for(int i=0;i<2*n+2;i++)
    {
        if(niz[i]>-1)
        {
            co++;
        }
    }
    printf("%i\n",co);
    for(int i=0;i<2*n+2;i++)
    {
        if(niz[i]>-1)
        {
            printf("%lld ",niz[i]);
        }
    }

    return 0;
}