#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int n,d,sum=0;
    scanf("%d%d",&n,&d);
    rep(i,n){int x;scanf("%d",&x);sum+=x;}
    if(sum+(n-1)*10>d)puts("-1");else printf("%d\n",(d-sum)/5);
    return 0;
}