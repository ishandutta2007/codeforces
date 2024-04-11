#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool prime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    long long int n; cin>>n;
    long long w=n*(n+1)/2;
    int xd=-1;
    if(n==1 || n==2) {cout<<"No"; return 0;}
    for(long long int i=2;i<=n;i++)
    {
        if(w%i==0 && prime(i)) {xd=i; break;}
    }
    if(xd==-1) cout<<"No";
    else
    {
        cout<<"Yes"<<endl;
        cout<<"1"<<" "<<xd<<endl;
        cout<<n-1<<" ";
        for(int i=1;i<=n;i++)
        {
            if(i!=xd) cout<<i<<" ";
        }
    }



    return 0;
}