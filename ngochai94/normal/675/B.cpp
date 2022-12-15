#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(long long i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000001
#define pb push_back

long long n,a,b,c,d;

bool ok(long long x)
{
    return x>=1 && x<=n;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>a>>b>>c>>d;
    long long ans=0;
    For(i,1,n+1)
    {
        if(ok(a+i-d)&&ok(b+i-c)&&ok(a+b+i-c-d)) ans++;
    }
    cout<<ans*n;
}