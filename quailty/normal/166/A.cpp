#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
struct team
{
    int s,p;
    void input()
    {
        scanf("%d%d",&s,&p);
    }
    bool operator < (const team &r)const
    {
        return s==r.s ? p<r.p : s>r.s;
    }
    bool operator == (const team &r)const
    {
        return s==r.s && p==r.p;
    }
}t[55];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        t[i].input();
    }
    sort(t+1,t+n+1);
    int cnt=0;
    team p=t[k];
    for(int i=1;i<=n;i++)
    {
        if(p==t[i])cnt++;
    }
    printf("%d",cnt);
    return 0;
}