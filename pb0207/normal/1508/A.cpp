#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

char s[3][N];

int cnt[3][2];

int n;

void solve()
{
    for(int i=0;i<3;i++)
        for(int j=i+1;j<3;j++)
            for(int k=0;k<2;k++)
            {
                int ss=max(cnt[i][k],cnt[j][k]);
                if(n*2+n*2-min(cnt[i][k],cnt[j][k])<=n*3)
                {
                    string ans;
                    int p=1,q=1,lp,lq;
                    for(int t=0;t<=ss;t++)
                    {
                        lp=p,lq=q;
                        while(p<=n*2&&s[i][p]!=k+'0')
                            p++;
                        while(q<=n*2&&s[j][q]!=k+'0')
                            q++;
                        int tot=max(p-lp,q-lq);
                        if(p+1<=n*2)
                            p++;
                        if(q+1<=n*2)
                            q++;
                        for(int x=0;x<tot;x++)
                            ans+=(k^1)+'0';
                        ans+=k+'0';
                    }
                    ans.pop_back();
                    cout<<ans<<endl;
                    return;
                }
            }
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<3;i++)
            scanf("%s",s[i]+1),cnt[i][0]=cnt[i][1]=0;
        for(int i=0;i<3;i++)
            for(int j=1;j<=n*2;j++)
                cnt[i][s[i][j]-'0']++;
        solve();
    }
}