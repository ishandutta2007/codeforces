#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int cal(int a,int b,int n){return a<=b?b-a:2*n-a-b;}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,m,x1,y1,x2,y2;
        scanf("%d%d%d%d%d%d",&n,&m,&x1,&y1,&x2,&y2);
        printf("%d\n",min(cal(x1,x2,n),cal(y1,y2,m)));
    }
    return 0;
}