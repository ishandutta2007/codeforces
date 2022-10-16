#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int f(vector<int> a)
{
    sort(a.begin(),a.end());
    if(a.size()==0) return 0;
    int mini=a[0];
    vector<int> b;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]%mini!=0) b.push_back(a[i]);
    }
    return 1+f(b);
}

int main()
{
    int n; cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a.push_back(x);
    }
    cout<<f(a);


    return 0;
}