#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef double db;
const int MAXN=1000005;
int usd[MAXN];
vector<int> loc[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<MAXN;i++)
        loc[i].push_back(0);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        loc[a].push_back(i);
        usd[a]=1;
    }
    for(int i=0;i<MAXN;i++)
        loc[i].push_back(n+1);
    ll tot=1LL*n*n,now=0;
    for(int i=0;i<MAXN;i++)
    {
        if(!usd[i])continue;
        now+=tot;
        for(int j=1;j<(int)loc[i].size();j++)
        {
            int t=loc[i][j]-loc[i][j-1]-1;
            now-=1LL*t*t;
        }
    }
    return 0*printf("%.12f\n",1.0*now/tot);
}