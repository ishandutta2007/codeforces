#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
int cnt[MAXN],tmp[MAXN],dis,mx;
bool check(int n,int m)
{
    ///x+y=mx
    ///x=n-dis
    {
        int x=n-dis,y=mx-x;
        if(x>=0 && x<n && y>=0 && y<m)
        {
            for(int i=0;i<=mx;i++)
                tmp[i]=0;
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    tmp[abs(i-x)+abs(j-y)]++;
            bool isok=1;
            for(int i=0;i<=mx;i++)
                isok&=(tmp[i]==cnt[i]);
            if(isok)
            {
                printf("%d %d\n%d %d\n",n,m,x+1,y+1);
                return 1;
            }
        }
    }
    ///or y=m-dis
    {
        int y=m-dis,x=mx-y;
        if(x>=0 && x<n && y>=0 && y<m)
        {
            for(int i=0;i<=mx;i++)
                tmp[i]=0;
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    tmp[abs(i-x)+abs(j-y)]++;
            bool isok=1;
            for(int i=0;i<=mx;i++)
                isok&=(tmp[i]==cnt[i]);
            if(isok)
            {
                printf("%d %d\n%d %d\n",n,m,x+1,y+1);
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int a;
        scanf("%d",&a);
        cnt[a]++;
    }
    if(cnt[0]!=1)
        return 0*printf("-1\n");
    for(int i=1;i<MAXN;i++)
        if(cnt[i]<4*i)
        {
            dis=i;
            break;
        }
    for(int i=1;i<MAXN;i++)
        if(cnt[i]>4*i)
            return 0*printf("-1\n");
    for(int i=0;i<MAXN;i++)
        if(cnt[i])mx=i;
    for(int i=1;i*i<=t;i++)
        if(t%i==0 && check(i,t/i))
            return 0;
    return 0*printf("-1\n");
}