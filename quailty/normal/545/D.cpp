#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
ll t[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&t[i]);
    }
    sort(t,t+n);
    ll tot=0,ans=0;
    for(int i=0;i<n;i++)
    {
        if(t[i]>=tot)
        {
            tot+=t[i];
            ans++;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}