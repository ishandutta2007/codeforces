#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool spr(vector<int> a,int n,int p)
{
    int w=0;
    for(int i=0;i<a.size();i++)
    {

        w+=a[i]/n;
    }
    if(w>=p) return true;
    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int * a;
    a=new int[m];
    for(int i=0;i<m;i++) cin>>a[i];
    sort(a,a+m);
    vector<int> nowe;
    int w=1;
    for(int i=1;i<m;i++)
    {
        if(a[i]==a[i-1]) w++;
        else {nowe.push_back(w); w=1;}
    }
    nowe.push_back(w);
    int i=0;
    while(spr(nowe,i+1,n)) i++;
    cout<<i;
    return 0;
}