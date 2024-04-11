#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int n,c,now=0,last=0;
    scanf("%d%d",&n,&c);
    rep(i,n)
    {
        int t;scanf("%d",&t);
        if(t-last>c)now=1;
        else now++;
        last=t;
    }
    printf("%d\n",now);
    return 0;
}