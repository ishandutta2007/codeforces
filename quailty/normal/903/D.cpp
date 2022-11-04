#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const ll BASE=1000000000000000000LL;
int a[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    ll high=0,low=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        low+=1LL*(2*(i-1)-(n-1))*a[i];
        while(low>=BASE)low-=BASE,high++;
        while(low<0)low+=BASE,high--;
    }
    map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        low-=mp[a[i]-1],low+=mp[a[i]+1];
        while(low>=BASE)low-=BASE,high++;
        while(low<0)low+=BASE,high--;
        mp[a[i]]++;
    }
    if(high>=-1 && high<=0)printf("%lld\n",high*BASE+low);
    else if(high>0)printf("%lld%018lld\n",high,low);
    else printf("%lld%018lld\n",high+(low>0),(low>0)*BASE-low);
    return 0;
}