#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
char str[MAXN];
int solve()
{
    int n,cnt[2]={0,0};
    scanf("%d%s",&n,str);
    str[n]='W';
    for(int i=0;i<=n;i++)
    {
        if(str[i]=='W')
        {
            if((cnt[0]!=0 && cnt[1]==0)
            || (cnt[0]==0 && cnt[1]!=0))
                return 0*printf("NO\n");
            cnt[0]=cnt[1]=0;
        }
        else cnt[str[i]=='R']++;
    }
    return 0*printf("YES\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}