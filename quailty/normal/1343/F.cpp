#include <bits/stdc++.h>
using namespace std;
const int MAXN=205;
int p[MAXN],loc[MAXN];
vector<int> seg[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1,k;i<n;i++)
        {
            scanf("%d",&k);
            seg[i].resize(k);
            for(int j=0;j<k;j++)
                scanf("%d",&seg[i][j]);
        }
        for(p[1]=1;p[1]<=n;p[1]++)
        {
            for(int i=1;i<=n;i++)
                loc[i]=0;
            loc[p[1]]=1;
            bool isok=1;
            for(int t=2;t<=n && isok;t++)
            {
                p[t]=0;
                for(int i=1;i<n;i++)
                {
                    if((int)seg[i].size()>t)continue;
                    int sp=0,cnt=0,mi=t;
                    for(int j=0;j<(int)seg[i].size();j++)
                    {
                        if(!loc[seg[i][j]])sp=seg[i][j],cnt++;
                        else mi=min(mi,loc[seg[i][j]]);
                    }
                    if(cnt==1 && mi>=t+1-(int)seg[i].size())
                    {
                        if(p[t])
                        {
                            isok=0;
                            break;
                        }
                        else p[t]=sp;
                    }
                }
                if(!p[t])isok=0;
                else loc[p[t]]=t;
            }
            if(isok)break;
        }
        for(int i=1;i<=n;i++)
            printf("%d%c",p[i]," \n"[i==n]);
    }
    return 0;
}