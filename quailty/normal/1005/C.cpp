#include<bits/stdc++.h>
using namespace std;
const int MAXN=120005;
int a[MAXN];
map<int,int> mp;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),mp[a[i]]++;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        for(int p=0;p<=30;p++)
        {
            int t=(1<<p)-a[i];
            cnt-=(t==a[i]);
            if(mp.find(t)!=mp.end())
                cnt+=mp[t];
        }
        if(cnt==0)res++;
    }
    printf("%d\n",res);
    return 0;
}