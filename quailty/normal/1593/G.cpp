#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
char str[MAXN];
int cnt[MAXN][2];
void solve()
{
    scanf("%s",str+1);
    int n=strlen(str+1);
    for(int i=1;i<=n;i++)
    {
        cnt[i][0]=cnt[i-1][0];
        cnt[i][1]=cnt[i-1][1];
        if(str[i]=='[' || str[i]==']')
            cnt[i][i&1]++;
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int c[2]={cnt[r][0]-cnt[l-1][0],cnt[r][1]-cnt[l-1][1]};
        printf("%d\n",abs(c[0]-c[1]));
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}