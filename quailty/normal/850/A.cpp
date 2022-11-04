#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int p[1005][5];
int cal(int a,int b,int c)
{
    int res=0;
    for(int i=0;i<5;i++)
        res+=(p[b][i]-p[a][i])*(p[c][i]-p[a][i]);
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=0;j<5;j++)
            scanf("%d",&p[i][j]);
    if(n>243)return 0*printf("0\n");
    vector<int> res;
    for(int i=1;i<=n;i++)
    {
        int isok=0;
        for(int j=1;j<=n;j++)
            if(j!=i)for(int k=1;k<=n;k++)
                if(k!=i && k!=j)
                    isok|=(cal(i,j,k)>0);
        if(!isok)res.push_back(i);
    }
    printf("%d\n",(int)res.size());
    for(int i=0;i<(int)res.size();i++)
        printf("%d ",res[i]);
    return 0;
}