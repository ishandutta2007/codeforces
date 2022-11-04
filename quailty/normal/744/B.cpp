#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
vector<int> query(int n,vector<int> que)
{
    printf("%d\n",(int)que.size());
    for(int i=0;i<(int)que.size();i++)
        printf("%d%c",que[i]," \n"[i+1==(int)que.size()]);
    fflush(stdout);
    vector<int>res(n);
    for(int i=0;i<n;i++)
        scanf("%d",&res[i]);
    return res;
}
vector<int>res[10][2];
int main()
{
    int n,d=0;
    scanf("%d",&n);
    while((1<<d)<n)d++;
    for(int i=0;i<d;i++)
        for(int j=0;j<2;j++)
        {
            vector<int>tmp;
            for(int k=0;k<n;k++)
                if((k>>i&1)==j)tmp.push_back(k+1);
            res[i][j]=query(n,tmp);
        }
    vector<int>ans(n,INF);
    for(int k=0;k<n;k++)
        for(int i=0;i<d;i++)
        {
            int j=(k>>i&1)^1;
            ans[k]=min(ans[k],res[i][j][k]);
        }
    printf("-1\n");
    for(int i=0;i<n;i++)
        printf("%d%c",ans[i]," \n"[i+1==n]);
    return 0;
}