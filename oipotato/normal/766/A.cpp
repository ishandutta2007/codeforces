#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char a[100010],b[100010];
int main()
{
    scanf("%s%s",a+1,b+1);
    int n=strlen(a+1),m=strlen(b+1);
    bool flag=1;
    rep(i,min(n,m))if(a[i]!=b[i])flag=0;
    printf("%d\n",n!=m||!flag?max(n,m):-1);
    return 0;
}