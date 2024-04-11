#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100005;
int fac[MAXN];
ll solve(vector<vector<int> > perm)
{
    int n=(int)perm.size();
    vector<vector<int> > idx;
    int pre[8]={0};
    for(int i=0;i<8;i++)
        for(int j=0;j<3;j++)
            if(i>>j&1)pre[i]=__gcd(pre[i],perm[0][j]);
    for(int i=0;i<n;i++)
    {
        vector<int> tmp;
        for(int j=0;j<3;j++)
            tmp.push_back(lower_bound(perm[0].begin(),perm[0].end(),perm[i][j])-perm[0].begin());
        for(int j=0;j<3;j++)
            tmp[j]=(1<<tmp[j]);
        idx.push_back(tmp);
    }
    ll res1=0,res2=0;
    for(int i=1;i<(1<<n);i++)
    {
        vector<int> now(3,0);
        ll cof=-1;
        for(int j=0;j<n;j++)if(i>>j&1)
        {
            cof*=-1;
            for(int k=0;k<3;k++)
                now[k]|=idx[j][k];
        }
        res1+=cof*fac[pre[now[0]]]*fac[pre[now[1]]]*fac[pre[now[2]]];
        res2+=cof*fac[pre[now[0]|now[1]]]*fac[pre[now[2]]];
    }
    ll res3=fac[__gcd(perm[0][0],__gcd(perm[0][1],perm[0][2]))];
    res2=3*(res2-res3),res1=res1-res2-res3;
    return res1/6+res2/3+res3;
}
int main()
{
    for(int i=1;i<MAXN;i++)
        for(int j=i;j<MAXN;j+=i)
            fac[j]++;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int A,B,C;
        scanf("%d%d%d",&A,&B,&C);
        vector<vector<int> > perm;
        perm.push_back({A,B,C});
        perm.push_back({A,C,B});
        perm.push_back({B,A,C});
        perm.push_back({B,C,A});
        perm.push_back({C,A,B});
        perm.push_back({C,B,A});
        sort(perm.begin(),perm.end());
        perm.erase(unique(perm.begin(),perm.end()),perm.end());
        printf("%lld\n",solve(perm));
    }
    return 0;
}