#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
set<int>la,now;
char cmd[105][5];
int in[105];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%s%d",cmd[i],&in[i]);
    la.clear();
    now.clear();
    for(int i=1;i<=n;i++)
    {
        if(cmd[i][0]=='+')
        {
            now.insert(in[i]);
        }
        else
        {
            if(now.find(in[i])==now.end())la.insert(in[i]);
            else now.erase(in[i]);
        }
    }
    int ans=la.size();
    for(int i=1;i<=n;i++)
    {
        if(cmd[i][0]=='+')
        {
            la.insert(in[i]);
        }
        else
        {
            la.erase(in[i]);
        }
        ans=max(ans,(int)la.size());
    }
    printf("%d\n",ans);
    return 0;
}