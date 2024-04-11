#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
int a[MAXN],b[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        vector<ll> cnt[2];
        for(int i=0;i<2;i++)
            cnt[i].push_back(0);
        for(int i=1;i<=n;i++)
            cnt[b[i]-1].push_back(a[i]);
        for(int i=0;i<2;i++)
            sort(cnt[i].begin()+1,cnt[i].end(),greater<ll>());
        for(int i=0;i<2;i++)
            for(size_t j=1;j<cnt[i].size();j++)
                cnt[i][j]+=cnt[i][j-1];
        int res=-1;
        for(int i=0;i<(int)cnt[0].size();i++)
        {
            if(cnt[0][i]+cnt[1].back()<m)continue;
            int j=lower_bound(cnt[1].begin(),cnt[1].end(),m-cnt[0][i])-cnt[1].begin();
            if(res<0 || res>i+j*2)res=i+j*2;
        }
        printf("%d\n",res);
    }
    return 0;
}