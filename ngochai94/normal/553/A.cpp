#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-8
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

long long c[1111][1111],n,s,val,ans;

long long inv(int x)
{
    long long ret=1,m=mod-2;
    for(int i=30;i>=0;i--)
    {
        ret*=ret;
        ret%=mod;
        if(m&(1<<i))
        {
            ret*=x;
            ret%=mod;
            //cout<<m<<endl;
        }
        //cout<<ret<<endl;
    }
    return ret;
}

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    cin>>s;
    ans=1;
    //cout<<inv(2)<<endl;return 0;
    For(i,1,1111)
    {
        c[i][0]=1;
        For(j,1,i+1)
        {
            c[i][j]=c[i][j-1]*(i-j+1);
            c[i][j]%=mod;
            c[i][j]*=inv(j);
            c[i][j]%=mod;
        }
    }
    while(--n)
    {
        cin>>val;
        ans*=c[s+val-1][val-1];
        s+=val;
        ans%=mod;
        //cout<<ans<<endl;
    }
    cout<<ans;
}