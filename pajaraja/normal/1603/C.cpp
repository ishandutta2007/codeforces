#include <bits/stdc++.h>
#define MAXN 100007
#define MOD 998244353
using namespace std;
int a[MAXN];
vector<int> v[2];
vector<long long> cnt[2];
void flors(int i,int c)
{
    v[c].clear();
    int t=1;
    while(t*t<a[i]) {v[c].push_back(t); t++;}
    if(a[i]==t*t) v[c].push_back(t);
    t--;
    while(t>0) {if(a[i]/t!=v[c][v[c].size()-1]) v[c].push_back(a[i]/t); t--;}
    reverse(v[c].begin(),v[c].end());
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,c=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        flors(n,0);
        cnt[0].push_back(1);
        for(int i=0;i+1<v[0].size();i++) cnt[0].push_back(0);
        long long sol=0;
        for(int i=n-1;i>=1;i--)
        {
            flors(i,c);
            int t=0;
            for(int j=0;j<v[c].size();j++)
            {
                int r=v[c][j];
                long long total=0;
                while(t<v[c^1].size() && v[c^1][t]>=r)
                {
                    if(v[c^1][t]==r && a[i]%r!=0) break;
                    total+=cnt[c^1][t];
                    if(v[c^1][t]==r) sol+=((((long long)i)*(a[i]/r-1LL))%MOD)*cnt[c^1][t];
                    else sol+=((((long long)i)*((a[i]-1LL)/(r+1LL)))%MOD)*cnt[c^1][t];
                    sol%=MOD;
                    t++;
                }
                cnt[c].push_back(total);
            }
            cnt[c][0]++;
            cnt[c^1].clear(); v[c^1].clear();
            c^=1;
        }
        printf("%lld\n",sol);
        v[0].clear(); cnt[0].clear();
        v[1].clear(); cnt[1].clear();
    }
}