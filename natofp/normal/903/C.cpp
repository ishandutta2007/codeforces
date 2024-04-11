#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n; cin>>n;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int naj=0;
    int akt=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1]) akt++;
        else
        {
            naj=max(naj,akt);
            akt=1;
        }
    }
    naj=max(naj,akt);
    cout<<naj;
    return 0;
}