#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   int * a;
   a=new int[n];
   for(int i=0;i<n;i++) cin>>a[i];
   sort(a,a+n);
   vector<pair<int,int> > xd;
   int k=1;
   int l=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1]) {k++;}
        else {xd.push_back(make_pair(l,k)); l++; k=1;}
    }
    xd.push_back(make_pair(l,k));
    int sum=xd[0].second;
    int odp=0;
    for(int i=1;i<xd.size();i++)
    {
        int k=xd[i].second;
        odp+=min(sum,k);
        sum-=min(sum,k);
        sum+=k;


    }
    cout<<odp;
    return 0;
}