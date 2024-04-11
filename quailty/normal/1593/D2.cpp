#include<bits/stdc++.h>
using namespace std;
const int MAXN=45;
const int MAXA=2000005;
int a[MAXN];
int solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i+n/2-1<=n;i++)
        if(a[i]==a[i+n/2-1])
            return 0*printf("-1\n");
    vector<int> can;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int d=a[j]-a[i];
            if(!d)continue;
            for(int k=1;k*k<=d;k++)if(d%k==0)
                can.push_back(k),can.push_back(d/k);
        }
    sort(can.begin(),can.end());
    can.erase(unique(can.begin(),can.end()),can.end());
    reverse(can.begin(),can.end());
    int res=0;
    for(auto c : can)
    {
        static int cnt[MAXA];
        for(int i=1;i<=n;i++)
            cnt[(a[i]%c+c)%c]++;
        for(int i=1;i<=n;i++)
            if(cnt[(a[i]%c+c)%c]>=n/2)res=c;
        for(int i=1;i<=n;i++)
            cnt[(a[i]%c+c)%c]--;
        if(res)break;
    }
    return 0*printf("%d\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}