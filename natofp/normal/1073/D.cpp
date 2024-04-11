#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()

{
    ios_base::sync_with_stdio(0);
cin.tie(0);
    int n; long long int t; cin>>n>>t;
    int * a;
    a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    long long int ans=0;
    long long int suma=0;
    for(int i=0;i<n;i++) suma+=a[i];
    int naj=1e9+1;
    for(int i=0;i<n;i++) naj=min(naj,a[i]);
    int akt=0;
    vector<bool> czy(n,1);
    int ile=n;
    while(t>=naj)
    {
        if(t>=suma)
        {
            ans+=(t/suma)*ile;
            t%=suma;
        }
        else if(a[akt]<=t)
        {
             {ans++; t-=a[akt]; akt++; akt%=n;}
        }
        else if(czy[akt]==true)
        {
            ile--; suma-=a[akt]; czy[akt]=false; akt++; akt%=n;
        }
        else {akt++; akt%=n;}

    }
    cout<<ans;


    return 0;
}