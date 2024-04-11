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
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        if(m&1)
        {
            if(k>(m-1)/2*n||(k&1))puts("NO");
            else
            {
                puts("YES");
            }
        }
        else if(n&1)
        {
            if(k<m/2||(k&1)!=((m/2)&1))puts("NO");
            else
            {
                puts("YES");
            }
        }
        else
        {
            if(k&1)puts("NO");
            else
            {
                puts("YES");
            }
        }
    }
    return 0;
}