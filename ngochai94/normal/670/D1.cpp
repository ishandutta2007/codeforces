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

long long n,k,need[100005],has[100005],high,low,chs;

bool satisfy()
{
    long long kk=k;
    For(i,0,n) kk-=max(0ll,need[i]*chs-has[i]);
    if(kk>=0) return true;
    return false;
}

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>k;
    For(i,0,n) cin>>need[i];
    For(i,0,n) cin>>has[i];
    high=100005;low=0;
    while(low<high)
    {
        chs=(low+high)/2;
        if(satisfy()) low=chs+1;
        else high=chs;
    }
    cout<<low-1;
}