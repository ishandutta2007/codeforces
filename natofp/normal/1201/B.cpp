#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    int * a=new int[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int xdd=a[1];
    for(int i=1;i<=n;i++)
    {
        xdd=max(xdd,a[i]);
    }
    long long int sum=0;
    for(int i=1;i<=n;i++) sum+=a[i];
    if(sum%2==1)
    {
        cout<<"NO"<<endl; return 0;
    }
    if(xdd*2>sum)
    {
        cout<<"NO"<<endl; return 0;
    }
    cout<<"YES"<<endl;
    return 0;
}