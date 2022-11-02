#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int a[4][4];
    rep(i,3)rep(j,3)a[i][j]=1;
    rep(i,3)rep(j,3)
    {
        int x;scanf("%d",&x);
        if(!(x&1))continue;
        a[i][j]^=1;
        if(i>1)a[i-1][j]^=1;
        if(i<3)a[i+1][j]^=1;
        if(j>1)a[i][j-1]^=1;
        if(j<3)a[i][j+1]^=1;
    }
    rep(i,3){rep(j,3)printf("%d",a[i][j]);puts("");}
    return 0;
}