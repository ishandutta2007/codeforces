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
        vector<int>a(n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int mn=*min_element(a.begin(),a.end()),mx=*max_element(a.begin(),a.end());
        int ans=max(a[n-1]-mn,mx-a[0]);
        for(int i=0;i<n;i++)
            ans=max(ans,a[i]-a[(i+1)%n]);
        printf("%d\n",ans);
    }
}