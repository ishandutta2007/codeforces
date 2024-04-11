#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int main()
{
    int T;
    // for(scanf("%d",&T);T--;)
    {
        int n,c[2]={0,0};
        scanf("%d",&n);
        rep(i,n){int x;scanf("%d",&x);c[x&1]++;}
        if(c[1]&1)printf("%d\n",c[1]);else printf("%d\n",c[0]);
    }
    return 0;
}