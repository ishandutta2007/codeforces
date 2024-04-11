#include <bits/stdc++.h>
using namespace std;
int a[300005];
vector<int> v[300005];
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        v[a[i]].push_back(i);
    }
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    while (q--)
    {
        int l,r,ans=1;
        scanf("%d%d",&l,&r);
        for (int _=0;_<40;_++)
        {
            int c=a[uniform_int_distribution<int>(l,r)(rng)],f=upper_bound(v[c].begin(),v[c].end(),r)-lower_bound(v[c].begin(),v[c].end(),l);
            ans=max(ans,2*f-(r-l+1));
        }
        printf("%d\n",ans);
    }
}