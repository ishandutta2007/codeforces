#include<bits/stdc++.h>
using namespace std;
vector<int> val;
void dfs(int len,int now,int sum)
{
    if(sum==10)val.push_back(now);
    if(len>7 || sum>10)return;
    for(int i=(len==0);i<10;i++)
        dfs(len+1,now*10+i,sum+i);
}
int main()
{
    dfs(0,0,0);
    sort(val.begin(),val.end());
    int k;
    scanf("%d",&k);
    printf("%d\n",val[k-1]);
    return 0;
}