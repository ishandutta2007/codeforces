#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int a,b;scanf("%d%d",&a,&b);
    int ans=0;
    for(;a>0&&b>0;)
    {
        if(a<b)swap(a,b);
        a-=2;b+=1;
        if(a<0)break;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}