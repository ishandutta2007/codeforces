#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=100005;
vector<int>e[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int m,in;
    int loc=0;
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&m);
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&in);
            if(in==1)loc=i;
            e[i].push_back(in);
        }
    }
    int cnt=0;
    for(int i=0;i<e[loc].size();i++)
    {
        if(e[loc][i]==i+1)cnt++;
        else break;
    }
    int b=e[loc].size()-cnt+1;
    //printf("%d\n",b);
    int ans=2*b-2+2*n-2*e[loc].size()-(k-1);
    printf("%d\n",ans);
    return 0;
}