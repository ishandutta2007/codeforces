#include<bits/stdc++.h>
using namespace std;

int T;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        vector<int>a(n+1);
        set<int>s;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),s.insert(i);
        vector<int>ans(n+1);
        for(int i=1;i<n;i++)
        {
            if(a[i]<=a[i+1])
                continue;
            int x=a[i]-a[i+1];
            auto it=s.lower_bound(x);
            assert(it!=s.end());
            ans[*it]=i+1;
            s.erase(it);
        }
        for(int i=1;i<=n;i++)
            if(!ans[i])
                ans[i]=n;
        for(int i=1;i<=n;i++)
            printf("%d%c",ans[i]," \n"[i==n]);
    }
}