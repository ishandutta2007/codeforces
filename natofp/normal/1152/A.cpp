#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d;
    a=b=c=d=0;
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        if(x%2==0) a++;
        else b++;
    }
    for(int i=0;i<m;i++)
    {
        int x; cin>>x;
        if(x%2==0) c++;
        else d++;
    }
    cout<<min(a,d)+min(b,c);
    return 0;
}