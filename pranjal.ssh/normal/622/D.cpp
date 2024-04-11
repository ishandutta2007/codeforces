#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[2*n];
    memset(a,0,sizeof a);
    int x=0,y=2*n-1;
    for(int i=1;i<n;++i)
    {
        if(i&1)
        a[x]=i,a[x+n-i]=i,++x;
        else
        a[y]=i,a[y-(n-i)]=i,--y;
    }
    for(int i=0;i<2*n;++i)
    if(a[i]==0)a[i]=n;
    for(int i=0;i<2*n;++i)cout<<a[i]<<" ";
    return 0;
}