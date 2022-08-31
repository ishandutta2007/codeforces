#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int xo[n+1];
    xo[0]=0;
    
    int temp;
    
    
    for(int i=1;i<=n;i++)
    {
        cin >> temp;
        xo[i]=xo[i-1]^temp;
        
    }
    map<int,int> mymapodd;
    map<int,int> mymapeven;
    
    for(int i=0;i<=n;i++)
    {
        if(i%2==0)    mymapeven[xo[i]]++;
        else mymapodd[xo[i]]++;
    }
    
    long long ans=0;
    
    for(auto  x : mymapodd)
    {
     ans+=((1LL*x.second)*(x.second-1))/2;   
    }
    for(auto  x : mymapeven)
    {
     ans+=((1LL*x.second)*(x.second-1))/2;   
    }
    
    cout << ans;
    
    
    
    
}