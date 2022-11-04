#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef long long ll;
ll a[1005];
unordered_map<ll,int>mp;
ll t[105],cnt;
int main()
{
    mp.max_load_factor(0.1);
    mp.reserve(262144);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    for(int i=0;i<n;i++)
        mp[a[i]]++;
    int res=2;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i==j)continue;
            if(a[i]==0 && a[j]==0)res=max(res,mp[0]);
            else
            {
                t[0]=a[i];
                t[1]=a[j];
                ll now=t[0]+t[1];
                cnt=2;
                while(abs(now)<=1000000000)
                {
                    t[cnt++]=now;
                    now=t[cnt-2]+t[cnt-1];
                }
                t[cnt++]=now;
                mp[t[0]]--;
                mp[t[1]]--;
                for(int k=2;k<cnt;k++)
                {
                    if(mp.find(t[k])==mp.end() || mp[t[k]]==0)
                    {
                        res=max(res,k);
                        for(int tt=0;tt<k;tt++)mp[t[tt]]++;
                        break;
                    }
                    else mp[t[k]]--;
                }
            }
        }
    printf("%d\n",res);
    return 0;
}