#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    printf("%d\n",min(min(n,m),(n+m)/3));
    return 0;
}