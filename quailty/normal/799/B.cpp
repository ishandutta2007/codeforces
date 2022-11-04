#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
int p[MAXN],usd[MAXN];
vector<int> id[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    for(int _=0;_<2;_++)
        for(int i=1;i<=n;i++)
        {
            int t;
            scanf("%d",&t);
            id[t-1].push_back(i);
        }
    for(int i=0;i<3;i++)
    sort(id[i].begin(),id[i].end(),[](int a,int b){return p[a]<p[b];});
    int m,ptr[3]={0,0,0};
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int c;
        scanf("%d",&c);
        while(ptr[c-1]<(int)id[c-1].size())
        {
            if(!usd[id[c-1][ptr[c-1]]])
            {
                usd[id[c-1][ptr[c-1]]]=1;
                break;
            }
            ptr[c-1]++;
        }
        if(ptr[c-1]>=(int)id[c-1].size())printf("-1 ");
        else printf("%d ",p[id[c-1][ptr[c-1]]]);
        ptr[c-1]++;
    }
    return 0;
}