#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int n;scanf("%d",&n);
    rep(i,n)
    {
        int x;scanf("%d",&x);
        printf("%d%c",x-!(x&1)," \n"[i==n]);
    }
    return 0;
}