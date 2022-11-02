#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[20],n;
bool dfs(int k,int now,int num)
{
    if(num&&!now)return 1;
    if(k>n)return 0;
    if(dfs(k+1,now-a[k],num+1))return 1;
    if(dfs(k+1,now+a[k],num+1))return 1;
    if(dfs(k+1,now,num))return 1;
    return 0;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]);
        puts(dfs(1,0,0)?"YES":"NO");
    }
    return 0;
}