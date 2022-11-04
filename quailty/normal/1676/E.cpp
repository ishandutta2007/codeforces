#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int n,q;
    scanf("%d%d",&n,&q);
    vector<int> a(n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a.begin(),a.end(),greater<int>());
    for(int i=1;i<n;i++)
        a[i]+=a[i-1];
    while(q--)
    {
        int x;
        scanf("%d",&x);
        int res=lower_bound(a.begin(),a.end(),x)-a.begin()+1;
        printf("%d\n",res<=n ? res : -1);
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}