#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    vector<pair<int,int> >t;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            t.push_back(make_pair(i,(i&1 ? j : m+1-j)));
    for(int i=1;i<=k-1;i++)
    {
        printf("2");
        for(int j=0;j<2;j++)
        {
            pair<int,int>r=t.back();
            printf(" %d %d",r.first,r.second);
            t.pop_back();
        }
        printf("\n");
    }
    printf("%d",(int)t.size());
    while(!t.empty())
    {
        pair<int,int>r=t.back();
        printf(" %d %d",r.first,r.second);
        t.pop_back();
    }
    return 0;
}