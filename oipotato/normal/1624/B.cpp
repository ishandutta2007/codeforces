#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
bool check(int x,int y)
{
    return y>0&&y%x==0;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(check(c,2*b-a)||((a+c)%2==0&&check(b,(a+c)/2))||check(a,2*b-c))puts("YES");
        else puts("NO");
    }
    return 0;
}
//a+c=2b