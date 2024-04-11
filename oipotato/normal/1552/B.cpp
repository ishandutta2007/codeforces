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
int r[50010][10],n;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%d",&n);
        rep(i,n)rep(j,5)scanf("%d",&r[i][j]);
        int now=1;
        for(int i=2;i<=n;i++)
        {
            int cnt=0;
            rep(j,5)cnt+=r[now][j]<r[i][j];
            if(cnt<3)now=i;
        }
        bool flag=1;
        rep(i,n)
        {
            if(i==now)continue;
            int cnt=0;
            rep(j,5)cnt+=r[now][j]<r[i][j];
            if(cnt<3){flag=0;break;}
        }
        printf("%d\n",flag?now:-1);
    }
    return 0;
}