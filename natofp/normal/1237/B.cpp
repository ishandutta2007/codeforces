#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=1e5+5;
const int roz=(1<<18);

int t[roz];

int qq(int lo,int hi,int u,int a,int b)
{
    if(lo==a && b==hi) return t[u];
    if(b<=a) return 0;
    int mid=(lo+hi)/2;
    int l=qq(lo,mid,u*2,a,min(b,mid));
    int r=qq(mid,hi,u*2+1,max(a,mid),b);
    return l+r;
}

void dodaj(int pos)
{
    pos+=roz/2;
    while(pos>=1)
    {
        t[pos]++;
        pos/=2;
    }
}

int a[nax];
int b[nax];
int n;

int odw[nax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) odw[b[i]]=i;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int sumka=qq(0,roz/2,1,1,odw[a[i]]+1);
        //cout<<sumka<<endl;
        if(sumka<i-1) res++;
        dodaj(odw[a[i]]);
    }
    cout<<res;
    return 0;
}