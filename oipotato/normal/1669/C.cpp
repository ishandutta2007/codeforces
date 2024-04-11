#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,f[2]={0,0};
        scanf("%d",&n);
        rep(i,n){int x;scanf("%d",&x);f[i&1]|=1<<(x&1);}
        puts(f[0]!=3&&f[1]!=3?"YES":"NO");
    }
    return 0;
}