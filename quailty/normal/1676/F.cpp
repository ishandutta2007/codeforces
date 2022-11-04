#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> a(n),b;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b.push_back(a[i]);
        b.push_back(a[i]+1);
    }
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    vector<int> c(b.size());
    for(int i=0;i<n;i++)
        c[lower_bound(b.begin(),b.end(),a[i])-b.begin()]++;
    int l=0,r=-1;
    for(int i=0,j=0;i<(int)c.size();i=j)
    {
        if(c[i]<k)
        {
            j=i+1;
            continue;
        }
        while(j<(int)c.size() && c[j]>=k)++j;
        if(j-i>r-l)l=i,r=j;
    }
    if(r<0)printf("-1\n");
    else printf("%d %d\n",b[l],b[r-1]);
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}