#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(n==1)return 0*printf("YES\n1000000000 1000000000\n");
    vector<int> gap;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i+1])return 0*printf("NO\n");
        gap.push_back(abs(a[i]-a[i+1]));
    }
    sort(gap.begin(),gap.end(),greater<int>());
    gap.erase(unique(gap.begin(),gap.end()),gap.end());
    if((int)gap.size()>2)printf("NO\n");
    else
    {
        if((int)gap.size()==2 && gap[1]>1)
            return 0*printf("NO\n");
        if(gap[0]>1)for(int i=1;i<n;i++)
            if(fabs(a[i]-a[i+1])==1 && (a[i]-1)/gap[0]!=(a[i+1]-1)/gap[0])
                return 0*printf("NO\n");
        printf("YES\n1000000000 %d\n",gap[0]);
    }
    return 0;
}