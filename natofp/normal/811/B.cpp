#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=1e4+5;
int a[nax];
int n,m;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(m--)
    {
        int l,r,x;
        cin>>l>>r>>x;
        int val=a[x];
        int res=0;
        for(int i=l;i<=r;i++)
        {
            if(a[i]<val) res++;
        }
        if(res==x-l) {cout<<"Yes"<<endl;}
        else cout<<"No"<<endl;
    }
    return 0;
}