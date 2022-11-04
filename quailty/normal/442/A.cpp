#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const char ty[]="RGBYW";
pair<int,int> card[105];
bool check(int m1,int m2,int n)
{
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            bool isok=0;
            if(card[i].first!=card[j].first && ((m1&(1<<card[i].first)) || (m1&(1<<card[j].first))))isok=1;
            if(card[i].second!=card[j].second && ((m2&(1<<card[i].second)) || (m2&(1<<card[j].second))))isok=1;
            if(!isok)return 0;
        }
    return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char buf[5];
        scanf("%s",buf);
        for(int j=0;j<5;j++)
            if(buf[0]==ty[j])
                card[i].first=j;
        card[i].second=buf[1]-'1';
    }
    sort(card+1,card+n+1);
    n=unique(card+1,card+n+1)-(card+1);
    int res=10;
    for(int i=0;i<32;i++)
        for(int j=0;j<32;j++)
            if(check(i,j,n))
                res=min(res,__builtin_popcount(i)+__builtin_popcount(j));
    printf("%d",res);
    return 0;
}