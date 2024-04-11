#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int n,f[2]={0,0};
    scanf("%d",&n);
    rep(i,n){int x;scanf("%d",&x);f[x&1]++;}
    printf("%d\n",min(f[0],f[1]));
    return 0;
}