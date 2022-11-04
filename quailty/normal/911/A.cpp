#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int mi=a[1];
    for(int i=1;i<=n;i++)
        mi=min(mi,a[i]);
    vector<int> loc;
    for(int i=1;i<=n;i++)
        if(a[i]==mi)loc.push_back(i);
    int res=n;
    for(int i=0;i+1<(int)loc.size();i++)
        res=min(res,loc[i+1]-loc[i]);
    printf("%d\n",res);
    return 0;
}