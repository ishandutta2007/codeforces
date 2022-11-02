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
        int n;scanf("%d",&n);
        char s[110];scanf("%s",s+1);
        int pos=-1;
        rep(i,n)if(s[i]=='8'){pos=i;break;}
        puts(pos==-1||pos+10>n?"NO":"YES");
    }
    return 0;
}