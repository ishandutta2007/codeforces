#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

long long n,b,k,x,v[111],ans[111],tmp[111],val,digit,off;

long long expo(long long l)
{
    // 10^l % x
    long long ret=1;
    for(int i=30;i>=0;i--)
    {
        ret*=ret;
        ret%=x;
        if(l&(1<<i)) ret*=10;
        ret%=x;
    }
    return ret;
}

void mul()
{
    reset(tmp,0);
    off=10%x;
    For(i,0,x) For(j,0,x)
    {
        tmp[(i*off+j)%x]+=ans[i]*v[j];
        tmp[(i*off+j)%x]%=mod;
    }
    For(i,0,x) ans[i]=tmp[i];
    digit+=1;
    //For(i,0,x) cout<<ans[i]<<' ';cout<<endl;
}

void m2()
{
    reset(tmp,0);
    off=expo(digit);
    //cout<<digit<<endl;
    For(i,0,x) For(j,0,x)
    {
        tmp[(i*off+j)%x]+=ans[i]*ans[j];
        tmp[(i*off+j)%x]%=mod;
    }
    For(i,0,x) ans[i]=tmp[i];
    digit*=2;
    //For(i,0,x) cout<<ans[i]<<' ';cout<<endl;
}

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>b>>k>>x;
    //cout<<expo(1);return 0;
    while(n--)
    {
        cin>>val;
        v[val%x]++;
    }
    reset(ans,0);
    ans[0]=1;
    digit=0;
    for(int i=30;i>=0;i--)
    {
        m2();
        if(b&(1<<i)) mul();
    }
    //For(i,0,x) cout<<ans[i]<<' ';cout<<endl;
    //cout<<v[k]<<endl;mul();
    //mul();m2();
    cout<<ans[k];
}