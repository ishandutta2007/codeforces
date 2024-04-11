#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n; cin>>n;
    vector<long long int > a;
    for(int i=0;i<n;i++)
    {
        long long int x; cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    vector<long long int> roznice;
    for(int i=0;i<n-1;i++)
    {
        roznice.push_back(a[i+1]-a[i]);
    }
    sort(roznice.begin(),roznice.end());
    long long int p[100005];
    if(roznice.size()>0) p[0]=roznice[0];
    for(int i=1;i<roznice.size();i++)
    {
        p[i]=p[i-1]+roznice[i];
    }
    int q; cin>>q;
    n=roznice.size();
    while(q--)
    {
        long long int l,r; cin>>l>>r;
        long long int res=0;
        long long int ile=(r-l+1);
        res=ile;
        int lo=0;
        int hi=n-1;
        if(hi<0)
        {
            cout<<ile<<endl;
            continue;
        }
        if(roznice[hi]<=ile)
        {
            res+=p[hi];
            cout<<res<<" ";
            continue;
        }
        while(lo+1<hi)
        {
            int mid=(lo+hi)/2;
            if(roznice[mid]<=ile) lo=mid+1;
            else hi=mid;
        }
        while(roznice[lo]<=ile && lo<=hi) lo++;
        lo--;
        if(lo>=0) res+=p[lo];
        res+=ile*(n-1-lo);
        cout<<res<<" ";
    }



    return 0;
}