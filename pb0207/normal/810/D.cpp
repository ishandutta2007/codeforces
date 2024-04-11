#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

int n,k;

bool query(int x,int y)
{
    if(x<1||y>n)
        return false;
    char s[101];
    cout<<1<<" "<<x<<" "<<y<<endl;
    fflush(stdout);
    scanf("%s",s);
    return s[0]=='T';
}

int get(int l,int r)
{
    if(l>r)
        return -1;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(query(mid,mid+1))
            r=mid;
        else
            l=mid+1;
    }
    return l;
}

int main()
{
    scanf("%d%d",&n,&k);
    int x,y;
    x=get(1,n);
    y=get(1,x-1);
    if(!query(y,x))
        y=get(x+1,n);
    cout<<2<<" "<<x<<" "<<y<<endl;
    fflush(stdout);
    return 0;
}