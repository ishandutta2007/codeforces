#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll a[MAXN],b[MAXN],res[MAXN];
void solve(int n,int k,int x)
{
    set<pair<ll,int> >st;
    for(int i=1;i<=n;i++)
        st.insert(make_pair(b[i],i));
    while(k--)
    {
        pair<ll,int>tmp=*st.begin();
        st.erase(st.begin());
        b[tmp.second]+=x;
        st.insert(make_pair(b[tmp.second],tmp.second));
    }
}
int main()
{
    int n,k,x;
    scanf("%d%d%d",&n,&k,&x);
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        b[i]=abs(a[i]);
    }
    int sgn=1;
    for(int i=1;i<=n;i++)
        sgn^=(a[i]<0);
    if(sgn)
    {
        int loc=1;
        for(int i=1;i<=n;i++)
            if(b[i]<b[loc])loc=i;
        if(b[loc]-1LL*k*x>=0)
            b[loc]-=1LL*k*x;
        else
        {
            ll tmp=b[loc]/x+1;
            k-=tmp;
            if(a[loc]>=0)a[loc]-=tmp*x;
            else a[loc]+=tmp*x;
            b[loc]=abs(a[loc]);
            sgn^=1;
            solve(n,k,x);
        }
    }
    else solve(n,k,x);
    for(int i=1;i<=n;i++)
        res[i]=(a[i]>0 ? 1 : -1)*b[i];
    sgn^=1;
    for(int i=1;i<=n;i++)
        sgn^=(res[i]<0);
    if(sgn)for(int i=1;i<=n;i++)if(a[i]==0)
    {
        res[i]=-res[i];
        break;
    }
    for(int i=1;i<=n;i++)
        printf("%I64d ",res[i]);
    return 0;
}