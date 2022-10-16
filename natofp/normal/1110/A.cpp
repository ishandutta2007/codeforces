#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int b,k; cin>>b>>k;
    int * a=new int[k];
    for(int i=0;i<k;i++) cin>>a[i];
    int ans=0;
    for(int i=0;i<k;i++)
    {
        if(i!=(k-1))
        {
            if(b%2==0) continue;
            else ans+=a[i];
            ans%=2;
        }
        else ans+=a[i];
        ans%=2;
    }
    if(ans==0) cout<<"even";
    else cout<<"odd";
    return 0;
}