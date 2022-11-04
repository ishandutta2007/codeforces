#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,v;
    scanf("%d%d",&n,&v);
    vector<int>res;
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        int mi=1000000;
        for(int j=1;j<=k;j++)
        {
            int s;
            scanf("%d",&s);
            mi=min(mi,s);
        }
        if(v>mi)res.push_back(i);
    }
    printf("%d\n",(int)res.size());
    for(int i=0;i<(int)res.size();i++)
        printf("%d ",res[i]);
    return 0;
}