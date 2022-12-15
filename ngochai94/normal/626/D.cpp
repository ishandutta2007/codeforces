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

long long n,lis[2222],can[10005],gre[10005],ans,pos;
long double res;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    cin>>n;
    For(i,0,n) cin>>lis[i];
    sort(lis,lis+n);
    reset(can,0);
    For(i,0,n) For(j,i,n) can[lis[j]-lis[i]]++;
    gre[10005]=0;
    for(int i=10005;i>=0;i--)
    {
        gre[i]=gre[i+1]+can[i];
    }
    ans=0;
    For(i,1,5001) For(j,1,5001) ans+=can[i]*can[j]*gre[i+j+1];
    pos=n*(n-1)/2;
    res=1.0*ans/(pos);
    res/=pos;
    res/=pos;
    cout<<setprecision(11)<<res;
}