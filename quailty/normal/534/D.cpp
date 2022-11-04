#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>a[200005];
vector<int>ans;
int main()
{
    int n;
    scanf("%d",&n);
    int in;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&in);
        a[in].push_back(i);
    }
    int cnt=0;
    bool flag=0;
    for(int i=0;i<=n;i++)
    {
        //printf("%d\n",i);
        while(!a[i].size())
        {
            if(i<=2)
            {
                flag=1;
                break;
            }
            else i-=3;
        }
        if(flag)break;
        cnt++;
        //printf("%d\n",i);
        ans.push_back(a[i].back());
        a[i].pop_back();
    }
    if(cnt<n)printf("Impossible\n");
    else
    {
        printf("Possible\n");
        for(int i=0;i<ans.size();i++)
        {
            printf("%d ",ans[i]);
        }
    }
        return 0;
}