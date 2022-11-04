#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
vector<int>res;
int v[MAXN],p[MAXN];
bool cmp(int a,int b)
{
    return v[a]>v[b];
}
int main()
{
    int sum,limit;
    scanf("%d%d",&sum,&limit);
    for(int i=1;i<=limit;i++)
        v[i]=i&-i;
    for(int i=1;i<=limit;i++)
        p[i]=i;
    sort(p+1,p+limit+1);
    for(int i=limit;i>=1;i--)
        if(sum>=v[p[i]])
        {
            sum-=v[p[i]];
            res.push_back(p[i]);
        }
    if(sum)printf("-1");
    else
    {
        printf("%d\n",(int)res.size());
        for(int i=0;i<(int)res.size();i++)
            printf("%d ",res[i]);
    }
    return 0;
}