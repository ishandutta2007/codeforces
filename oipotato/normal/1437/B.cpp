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
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        char s[100010];scanf("%s",s+1);
        int ans=0;
        rep(i,n-1)if(s[i]==s[i+1])ans++;
        printf("%d\n",(ans+1)/2);
    }
    return 0;
}