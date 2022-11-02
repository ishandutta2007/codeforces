#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
    int x=max(a/10*3,a-a/250*c),y=max(b/10*3,b-b/250*d);
    if(x>y)puts("Misha");else if(x<y)puts("Vasya");else puts("Tie");
    return 0;
}