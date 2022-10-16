#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int dod=0;
    int minn=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>0) dod++;
        else if(a[i]<0) minn++;
    }
    if(dod*2>=n) {cout<<1; return 0;}
    if(minn*2>=n) {cout<<-1; return 0;}
    cout<<0;
    return 0;
}