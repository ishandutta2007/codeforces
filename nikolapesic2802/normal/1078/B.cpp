#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()
int dp[2][105][10005];
const int N=105;
const int mod=1e9+7;
vector<int> niz(N);
set<pair<int,pair<int,int> > > treba;
int nCrModp(int n, int r, int p=mod)
{
    int C[r+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}
int main()
{
    int sum=0;
    int n;
    scanf("%i",&n);
    map<int,int> lol;
    for(int i=0;i<n;i++){
        //niz[i]=i;
        scanf("%i",&niz[i]);
        sum+=niz[i];
        lol[niz[i]]++;
    }
    vector<pair<int,int> > arr;
    for(auto p:lol)
    {
        arr.pb(p);
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            for(int k=0;k<10005;k++)
            {
                if(i==0)
                {
                    if(j==0&&k==0)
                        dp[0][j][k]=1;
                    else
                        dp[0][j][k]=0;
                    continue;
                }
                if(j==0)
                {
                    if(k==0)
                    {
                        dp[i%2][j][k]=1;
                    }
                    else
                    {
                        dp[i%2][j][k]=0;
                    }
                    continue;
                }
                dp[i%2][j][k]=dp[(i+1)%2][j][k];
                if(k-niz[i-1]>=0)
                    dp[i%2][j][k]=(dp[i%2][j][k]+dp[(i+1)%2][j-1][k-niz[i-1]])%mod;
            }
        }
    }
    int poz=(n)%2;
    int res=1;
    for(auto p:arr)
    {
        for(int i=1;i<=p.second;i++)
        {
            int calc=nCrModp(p.second,i);
            if(calc==dp[poz][i][i*p.first])
            {
                res=max(res,i);
                if(i==p.second&&arr.size()==2)
                    res=max(res,n);
            }
            else
                break;
        }
        int t=p.second;
        int dd=sum-p.second*p.first;
        if(dp[poz][n-p.second][dd]==1)
        {
            res=max(res,p.second);
        }
    }
    printf("%i\n",res);
    return 0;
}