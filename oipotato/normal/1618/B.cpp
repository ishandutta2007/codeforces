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
        char last='c',s[3],cnt=0;
        int n;scanf("%d",&n);
        rep(i,n-2)
        {
            scanf("%s",s);
            if(s[0]!=last)putchar(s[0]),cnt++;
            putchar(last=s[1]);cnt++;
        }
        for(;cnt<n;putchar(last),cnt++);
        puts("");
    }
    return 0;
}