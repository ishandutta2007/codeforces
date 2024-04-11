#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[200010],b[10];
bool check(){return abs(b[3]-b[1])!=abs(b[3]-b[2])+abs(b[2]-b[1]);}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;
        scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]);
        int ans=2*n-1;
        rep(i,n-2)
        {
            rep(j,3)b[j]=a[i+j-1];
            if(check())
            {
                ans++;
                b[3]=a[i+3];
                if(!check())continue;
                b[2]=a[i+2];
                if(!check())continue;
                b[1]=a[i+1];
                if(!check())continue;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}