#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int res=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]==2 && a[i-1]==3) {cout<<"Infinite"; return 0;}
        if(a[i]==3 && a[i-1]==2) {cout<<"Infinite"; return 0;}
        if(a[i]==1)
        {
            if(a[i-1]==2) res+=3;
            else res+=4;
            continue;
        }
        if(a[i]==2 && a[i-1]==1)
        {
            if(i<=1 || a[i-2]!=3) res+=3;
            else res+=2;
            continue;
        }
        if(a[i]==3 && a[i-1]==1)
        {
            res+=4;
        }
    }
    cout<<"Finite"<<endl;
    cout<<res;
    return 0;
}