#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(long long i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000001
#define pb push_back

long long n,lis[100005],rmq[500000],ll[500000],rl[500000],ans[100005];

void proc(long long x,long long l,long long r)
{
    ll[x]=l;rl[x]=r;
    if(l==r) rmq[x]=r;
    else
    {
        proc(x*2,l,(l+r)/2);
        proc(x*2+1,(l+r)/2+1,r);
        if(lis[rmq[x*2]]>=lis[rmq[x*2+1]]) rmq[x]=rmq[x*2];
        else rmq[x]=rmq[x*2+1];
    }
}

long long f(long long l,long long r,long long x)
{
    if(l>rl[x]||r<ll[x]) return 0;
    if(l<=ll[x]&&r>=rl[x]) return rmq[x];
    long long a=f(l,r,x*2);
    long long b=f(l,r,x*2+1);
    if(lis[a]>lis[b]) return a;
    else return b;
}

long long getMax(long long l,long long r)
{
    return f(l,r,1);
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    For(i,1,n) cin>>lis[i];
    proc(1,1,n);
    int a,b;
    //cout<<rmq[8]<<' '<<ll[8]<<' '<<rl[8]<<endl;
    //cout<<getMax(1,3);return 0;
    for(long long i=n-1;i>0;i--)
    {
        if(lis[i]==n)
        {
            ans[i]=n-i;continue;
        }
        long long nex = getMax(i+1,lis[i]);
        ans[i] = ans[nex] + nex-i + n-lis[i];
    }
    long long ret = 0;
    For(i,1,n) ret+=ans[i];
    cout<<ret;
}