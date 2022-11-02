#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int n;
    char s[20];
    scanf("%d%s",&n,s+1);
    int cnt=0;
    int a[110];
    rep(i,n)if(s[i]>='2')
    {
        int x=s[i]-'0';
        if(x==4)a[++cnt]=2,a[++cnt]=2,a[++cnt]=3;
        else if(x==6)a[++cnt]=3,a[++cnt]=5;
        else if(x==8)a[++cnt]=2,a[++cnt]=2,a[++cnt]=2,a[++cnt]=7;
        else if(x==9)a[++cnt]=2,a[++cnt]=3,a[++cnt]=3,a[++cnt]=7;
        else a[++cnt]=x;
    }
    sort(a+1,a+cnt+1,greater<int>());
    rep(i,cnt)printf("%d",a[i]);puts("");
    return 0;
}