#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>ans;
int main()
{
    int n;
    scanf("%d",&n);
    int in;
    for(int i=1;i<=n;i++)
    {
        bool isok=1;
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&in);
            if(in==1 || in==3)isok=0;
        }
        if(isok)ans.push_back(i);
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}