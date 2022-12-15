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

long long n,k,pos,a[200005],sm,A;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>k;
    For(i,0,n+1) cin>>a[i];
    long long flag = 0;
    pos = n;
    sm=0;
    For(i,0,n+1)
    {
        sm/=2;
        sm+=a[i];
        if(sm%2)
        {
            pos=i;break;
        }
    }
    //cout<<pos;return 0;
    long long cur = 0;
    for(int i=n;i>pos;i--)
    {
        cur*=2;
        cur+=a[i];
        if(abs(cur)>=k*100)
        {
            cout<<0;return 0;
        }
    }
    cur*=2;
    if(abs(cur)>=k*100)
    {
        cout<<0;
        return 0;
    }
    int ans=0;
    //a[pos]+=cur;
    cur+=sm;
    //cout<<cur<<endl;
    for(int i=pos;i>=0;i--)
    {
        if(abs(a[i]-cur)<=k)
        {
            ans++;
            if(i==n&&a[i]==cur) ans--;
        }
        cur*=2;
        if(abs(cur)>100*k) break;
    }
    cout<<ans;
}