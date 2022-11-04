#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
vector<int>e[3005];
ll cnt[3005];
ll C(int k)
{
    return k*(k-1)/2;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
    }
    ll ans=0;
    vector<int>::iterator itr1,itr2;
    for(int i=1;i<=n;i++){
        memset(cnt,0,sizeof(cnt));
        int tot=e[i].size();
        for(itr1=e[i].begin();itr1!=e[i].end();itr1++){
            for(itr2=e[*itr1].begin();itr2!=e[*itr1].end();itr2++){
                cnt[*itr2]++;
            }
        }
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            ans+=C(cnt[j]);
        }
    }
    printf("%I64d\n",ans);
    return 0;
}