#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m; cin>>m;
    int * a=new int[m];
    for(int i=0;i<m;i++) cin>>a[i];
    int gcd=a[0];
    for(int i=0;i<m;i++)
    {
        if(a[i]%gcd!=0) {cout<<-1; return 0;}
    }
    cout<<2*m-1<<endl;
    cout<<a[0]<<" ";
    for(int i=1;i<m;i++)
    {
        cout<<gcd<<" "<<a[i]<<" ";
    }
    return 0;
}