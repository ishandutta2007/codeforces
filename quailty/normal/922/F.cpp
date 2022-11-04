#include<bits/stdc++.h>
using namespace std;
const int MAXN=300005;
int d[MAXN],pre[MAXN];
int main()
{
    for(int i=1;i<MAXN;i++)
        for(int j=i;j<MAXN;j+=i)
            d[j]++;
    int n,k;
    scanf("%d%d",&n,&k);
    if(n<=21)
    {
        int cnt[22];
        for(int i=1;i<(1<<n);i++)
        {
            for(int j=0;j<n;j++)
                cnt[j+1]=(i>>j&1);
            int now=0;
            for(int j=1;j<=n;j++)
                for(int t=2*j;t<=n;t+=j)
                    now+=cnt[j]*cnt[t];
            if(now==k)
            {
                printf("Yes\n%d\n",__builtin_popcount(i));
                for(int j=1,f=0;j<=n;j++)if(cnt[j])
                    f=(f ? printf(" "),1 : 1),printf("%d",j);
                return 0*printf("\n");
            }
        }
        return 0*printf("No\n");
    }
    else
    {
        int sum=0;
        for(int i=1;i<=n;i++)
            sum+=d[i]-1;
        if(k>sum)return 0*printf("No\n");
        vector<int> key[2];
        for(int i=n/2+1;i<=n;i++)if(d[i]==2)
            key[0].push_back(i),pre[i]=1;
        for(int i=n/3+1;i<=n/2;i++)if(d[i]==2)
        {
            key[1].push_back(2*i),pre[2*i]=1;
            key[1].push_back(i),pre[i]=1;
        }
        vector<int> res{1,2};
        int now=1;
        for(int i=3;i<=n;i++)if(!pre[i])
        {
            if(now+d[i]-1>k)break;
            res.push_back(i),now+=d[i]-1;
        }
        for(int i=0;i<=(int)key[1].size();i++)
            if(k-now-2*i<=(int)key[0].size())
            {
                for(int j=0;j<i;j++)
                    res.push_back(key[1][j]);
                for(int j=0;j<k-now-2*i;j++)
                    res.push_back(key[0][j]);
                break;
            }
        printf("Yes\n%d\n",(int)res.size());
        for(int i=0;i<(int)res.size();i++)
            printf("%d%c",res[i]," \n"[i==(int)res.size()-1]);
    }
    return 0;
}