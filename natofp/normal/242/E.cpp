#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int roz=(1<<18);

int tree[roz][20][2];

void update(int lo,int hi,int u,int a,int b,int lv)
{
    if(lo==a && b==hi)
    {
        tree[u][lv][1]++;
        if(tree[u][lv][1]==2) tree[u][lv][1]=0;
        tree[u][lv][0]=(b-a)-tree[u][lv][0];
        return ;
    }
    if(b<=a) return;
    int mid=(lo+hi)/2;
    update(lo,mid,u*2,a,min(b,mid),lv);
    update(mid,hi,u*2+1,max(a,mid),b,lv);
    tree[u][lv][0]=tree[u*2][lv][0]+tree[u*2+1][lv][0];
    if(tree[u][lv][1]==1) tree[u][lv][0]=(hi-lo)-tree[u][lv][0];

}

int get(int lo,int hi,int u,int a,int b,int lv)
{
    if(a==lo && b==hi)
    {
        return tree[u][lv][0];
    }
    if(b<=a) return 0;
    int mid=(lo+hi)/2;
    int x,y;
    x=get(lo,mid,u*2,a,min(b,mid),lv);
    y=get(mid,hi,u*2+1,max(a,mid),b,lv);
    int res=x+y;
    if(tree[u][lv][1]==1)
    {
        res=(b-a)-res;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<20;j++)
        {
            if(((1<<j)&(a[i]))!=0) update(0,roz/2,1,i,i+1,j);
        }
    }
    int m; cin>>m;
    while(m--)
    {
        int t; cin>>t;
        if(t==1)
        {
            int x,y; cin>>x>>y;
            x--; y--;
            long long int res=0;
            for(int i=0;i<20;i++)
            {
                res+=1LL*get(0,roz/2,1,x,y+1,i)*(1<<i);
            }
            cout<<res<<"\n";
        }
        else
        {
            int x,y,xd;
            cin>>x>>y>>xd;
            x--; y--;
            for(int i=0;i<20;i++)
            {
                if(((1<<i)&xd)!=0)
                {
                    update(0,roz/2,1,x,y+1,i);
                }
            }
        }
    }
    return 0;
}