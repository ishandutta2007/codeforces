#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int pr[10001][21];
int cur[10001],tmp[10001];

int find_bi(int l,int r,int v)
{
    int mid=(l+r)/2;
    while(l<mid)
    {
        if(tmp[mid]<=v)r=mid;
        else l=mid+1;
        mid=(l+r)/2;
    }
    if(l<r && tmp[mid]>v)mid++;
    return mid;
}

main()
{
    int a,b,c,d,e,f,x,y,z;
    cin>>a>>b;
    for(x=1;x<a;x++)cur[x]=tmp[x]=1;
    for(x=1;x<=b;x++)
    {
        for(y=a;y>=1;y--)
        {
            c=find_bi(y,a,a-y-tmp[y]);
            pr[y][x]=c;
            cur[y]=tmp[y]+tmp[c];
        }
        for(y=1;y<=a;y++)
        {
            cout<<pr[y][x]<<" ";
            tmp[y]=cur[y];
        }
        cout<<endl;
    }
}