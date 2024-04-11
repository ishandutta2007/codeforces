#include <iostream>
#include <bits/stdc++.h>

using namespace std;

 int tab[2222222][2];

int main()
{
    int n; cin>>n;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int * p=new int[n];
    p[0]=a[0];
    for(int i=1;i<n;i++) p[i]=p[i-1]^a[i];
    long long int ans=0;
    memset(tab,0,sizeof tab);
    for(int i=0;i<n;i++)
    {
        if(i%2==0) tab[p[i]][0]++;
        else tab[p[i]][1]++;
    }
    tab[0][1]++;
    for(int i=0;i<2222222;i++)
    {
        long long int t1,t2;
        t1=tab[i][0];
        t2=tab[i][1];
        if(t1>=2)
        {
            ans+=t1*(t1-1)/2;
        }
        if(t2>=2)
        {
            ans+=t2*(t2-1)/2;
        }
    }
    cout<<ans;
    return 0;
}