#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int * a; a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int naj=10000000;
    int t=0;
    int akt=0;
    for(int i=1;i<=n;i++)
    {
        akt=0;
        t=0;
        for(int j=1;j<=n;j++)
        {
            akt=0;
            akt+=abs(i-j);
            akt+=abs(j-1);
            akt+=abs(i-1);
            akt+=abs(i-1);
            akt+=(j-1);
            akt+=abs(i-j);
            t+=akt*(a[j-1]);
        }
        if(naj>t) naj=t;

    }
    cout<<naj;
    return 0;
}