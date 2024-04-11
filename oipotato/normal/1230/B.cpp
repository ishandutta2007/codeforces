#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int main()
{
    int T;
    // for(scanf("%d",&T);T--;)
    {
        int n,k;scanf("%d%d",&n,&k);
        char s[200010];scanf("%s",s+1);
        if(n==1&&k){puts("0");return 0;}
        if(s[1]!='1'&&k)k--,s[1]='1';
        rep(i,n)if(i!=1&&s[i]!='0'&&k)k--,s[i]='0';
        puts(s+1);
    }
    return 0;
}