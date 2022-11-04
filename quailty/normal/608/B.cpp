#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
char a[2][MAXN];
int c[MAXN];
int main()
{
    scanf("%s%s",a[0]+1,a[1]+1);
    int n[2];
    for(int i=0;i<2;i++)
        n[i]=strlen(a[i]+1);
    for(int i=1;i<=n[1];i++)
        c[i]=c[i-1]+(a[1][i]-'0');
    ll res=0;
    for(int i=1;i<=n[0];i++)
    {
        int t=c[n[1]-n[0]+i]-c[i-1];
        if(a[0][i]=='0')res+=t;
        else res+=n[1]-n[0]+1-t;
    }
    printf("%I64d\n",res);
    return 0;
}