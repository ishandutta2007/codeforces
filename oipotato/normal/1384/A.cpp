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
        char s[110];
        rep(i,100)s[i]='a';s[101]=0;
        puts(s+1);
        rep(i,n)
        {
            int x;scanf("%d",&x);x++;
            s[x]=s[x]=='a'?'b':'a';
            puts(s+1);
        }
    }
    return 0;
}