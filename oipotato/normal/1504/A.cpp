#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[300010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%s",s+1);
        int pos=-1,n=strlen(s+1);
        rep(i,n)if(s[i]!='a')pos=i;
        if(pos==-1){puts("NO");continue;}
        puts("YES");
        if(pos-1<=n-pos)
        {
            rep(i,n-(pos-1))putchar(s[i]);
            putchar('a');
            for(int i=n-(pos-1)+1;i<=n;i++)putchar(s[i]);
            puts("");
        }
        else
        {
            rep(i,n-pos)putchar(s[i]);
            putchar('a');
            for(int i=n-pos+1;i<=n;i++)putchar(s[i]);
            puts("");
        }
    }
    return 0;
}