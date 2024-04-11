#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    if(n<=2*k+1) {cout<<1<<endl<<n/2+1; return 0;}
    else if(n%(2*k+1)==0)
    {
        cout<<n/(2*k+1)<<endl;
        int x=k+1;
        while(x<=n) {cout<<x<<" "; x+=2*k+1;}
    }
    else
    {
        int t=n%(2*k+1);
        t+=2*k+1;
        int j=n-t;
        vector<int> res;
        int x=1;
        while(t>2*k+2 && x<=k) {x++; t--;}
        t-=2*k+1;
        res.push_back(x);
        for(int i=1;i<=j/(2*k+1);i++) res.push_back(x+(2*k+1)*i);
         res.push_back(n-t+1);
        cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
    }



    return 0;
}