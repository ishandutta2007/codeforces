#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a;
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a.push_back(x);
    }
    int idx=-1;
    int res=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i]>res)
        {
            res=a[i];
            idx=i;
        }
    }
    for(int i=1;i<idx;i++)
    {
        if(a[i]<a[i-1])
        {
            cout<<"NO"<<endl; return 0;
        }
    }
    for(int i=idx+2;i<n;i++)
    {
        if(a[i]>a[i-1])
        {
            cout<<"NO"<<endl; return 0;
        }
    }
    cout<<"YES";
    return 0;
}