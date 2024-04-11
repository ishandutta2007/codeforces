#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=5e5+5;
int a[nax];
int n;
map<int,int> odczytaj;
vector<int> x;
void kompresja()
{
    for(int i=1;i<=n;i++)
    {
        x.push_back(a[i]);
    }
    sort(x.begin(),x.end());
    for(int i=0;i<n;i++)
    {
        odczytaj[x[i]]=i+1;
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=odczytaj[a[i]];
    }
}

const int mod=1e9+7;
const int roz=(1<<20);

long long int tree[2][roz];
int ile[2][roz];

void dodaj(int numer,int pos,int val,int pluss)
{
    pos+=roz/2;
    while(pos>=1)
    {
        tree[numer][pos]+=val;
        ile[numer][pos]+=pluss;
        pos/=2;
    }
}

long long int query(int numer,int lo,int hi,int u,int a,int b)
{
    if(lo==a && b==hi)
    {
        return tree[numer][u];
    }
    if(b<=a) return 0;
    int mid=(lo+hi)/2;
    long long int res=query(numer,lo,mid,u*2,a,min(b,mid));
    res+=query(numer,mid,hi,u*2+1,max(a,mid),b);
    return res;
}

int ilezywych(int numer,int lo,int hi,int u,int a,int b)
{
    if(lo==a && b==hi)
    {
        return ile[numer][u];
    }
    if(b<=a) return 0;
    int mid=(lo+hi)/2;
    int res=ilezywych(numer,lo,mid,u*2,a,min(b,mid));
    res+=ilezywych(numer,mid,hi,u*2+1,max(a,mid),b);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(tree,0,sizeof tree);
    memset(ile,0,sizeof ile);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    kompresja();
    for(int i=1;i<=n;i++)
    {
        dodaj(1,a[i],i,1);
    }
    long long int res=0;
    for(int i=1;i<=n;i++)
    {
        long long int contribution=(long long int)i*(n-i+1);
        //cout<<i<<" "<<contribution<<endl;
        contribution%=mod;
        int ziomki=ilezywych(1,0,roz/2,1,0,a[i]);
        long long int suma=query(1,0,roz/2,1,0,a[i]);
        long long int plusik=(long long int)ziomki*(n+1)-suma;
        contribution+=plusik*i;
        suma=query(0,0,roz/2,1,0,a[i]);
        plusik=suma;
        contribution%=mod;
        contribution+=plusik*(n-i+1);
        contribution%=mod;
         //cout<<i<<" "<<contribution<<endl;
        contribution*=x[a[i]-1];
        contribution%=mod;
         //cout<<i<<" "<<contribution<<endl;
        res+=contribution;
        res%=mod;
        dodaj(1,a[i],-i,-1);
        dodaj(0,a[i],i,1);
    }
    cout<<res<<endl;
    return 0;
}