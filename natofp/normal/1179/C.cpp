#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int roz=(1<<21);

int tree[roz][2];
const int nax=3e5+5;
int a[nax];
int b[nax];

void dodaj(int lo,int hi,int u,int a,int b,int c)
{
    if(lo==a && b==hi)
    {
        tree[u][0]+=c;
        tree[u][1]+=c;
        return;
    }
    if(b<=a) return ;
    int mid=(lo+hi)/2;
    dodaj(lo,mid,u*2,a,min(b,mid),c);
    dodaj(mid,hi,u*2+1,max(a,mid),b,c);
    tree[u][0]=max(tree[u*2][0],tree[u*2+1][0])+tree[u][1];
}

int getmax(int lo,int hi,int u,int a,int b)
{
    if(lo==a && b==hi)
    {
        return tree[u][0];
    }
    if(b<=a) return -1e9;
    int mid=(lo+hi)/2;
    int l=getmax(lo,mid,u*2,a,min(b,mid));
    int r=getmax(mid,hi,u*2+1,max(a,mid),b);
    return max(l,r)+tree[u][1];
}

int szukaj()
{
    int pos=1;
    int bonus=0;
    bonus+=tree[1][1];
    while(pos<roz/2)
    {
        int prawo=tree[pos*2+1][0];
        prawo+=bonus;
        if(prawo>=1)
        {
            pos=pos*2+1;
            bonus+=tree[pos][1];
        }
        else
        {
            pos*=2;
            bonus+=tree[pos][1];
        }
    }
    return pos-roz/2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(tree,0,sizeof tree);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        a[i]=x;
        dodaj(0,roz/2,1,1,x+1,1);
    }
    for(int i=1;i<=m;i++)
    {
        int x; cin>>x;
        b[i]=x;
        dodaj(0,roz/2,1,1,x+1,-1);
    }
    int q; cin>>q;
    while(q--)
    {
        int t; cin>>t;
        if(t==1)
        {
            int v,x; cin>>v>>x;
            int last=a[v];
            dodaj(0,roz/2,1,1,last+1,-1);
            dodaj(0,roz/2,1,1,x+1,1);
            a[v]=x;
        }
        else
        {
            int v,x; cin>>v>>x;
            int last=b[v];
            dodaj(0,roz/2,1,1,last+1,1);
            dodaj(0,roz/2,1,1,x+1,-1);
            b[v]=x;
        }
        int naj=getmax(0,roz/2,1,1,1e6+1);
        if(naj<=0)
        {
            cout<<-1<<"\n";
        }
        else
        {
            cout<<szukaj()<<"\n";
        }
    }
    return 0;
}