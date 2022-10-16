#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int f(vector<int> a,int ile)
{
    if(a.size()==0) return 0;
    if(ile==1) return a.back();
    int res=0;
    if(a.size()>=1)
    {
        vector<int> b;
        int naj=a.back();
        for(int i=0;i<a.size()-1;i++)
        {
            int val=a[i];
            if(naj%val!=0) b.push_back(a[i]);
        }
        res=max(res,naj+f(b,ile-1));
    }
    if(a.size()>=2)
    {
        vector<int> b;
        int naj=a[a.size()-2];
        for(int i=0;i<a.size()-2;i++)
        {
            int val=a[i];
            if(naj%val!=0) b.push_back(a[i]);
        }
        res=max(res,naj+f(b,ile-1));
    }
    if(a.size()>=3)
    {
        vector<int> b;
        int naj=a[a.size()-3];
        for(int i=0;i<a.size()-3;i++)
        {
            int val=a[i];
            if(naj%val!=0) b.push_back(a[i]);
        }
        res=max(res,naj+f(b,ile-1));
    }
    return res;
}



int main()
{
    vector<int> a;
    vector<int> b;
    int q; cin>>q;
    while(q--)
    {
        a.clear();
        b.clear();
        int n; cin>>n;
        for(int i=0;i<n;i++)
        {
            int x; cin>>x;
            b.push_back(x);
        }
        sort(b.begin(),b.end());
        a.push_back(b[0]);
        for(int i=1;i<n;i++)
        {
            if(b[i]!=b[i-1]) a.push_back(b[i]);
        }
        cout<<f(a,3)<<endl;
    }
    return 0;
}