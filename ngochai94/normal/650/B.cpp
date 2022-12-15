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

long long n,a,b,t,toright[500005],toleft[500005];
string s;

bool can(long long x){
    // cout<<toright[x-1]+a*(x-1)<<endl;
    if(t>=toright[x-1]+a*(x-1)||t>=toleft[(n+1-x)%n]+a*(x-1)) return true; 
    For(i,2,x){
        long long j=x-i;
        // cout<<i<<endl;
        // cout<<toright[i-1]+toleft[(n-j)%n]-toleft[0]+a*min(i+i-2+j,j+j+i-1)<<endl;
        if(t>=toright[i-1]+toleft[(n-j)%n]-toleft[0]+a*min(i+i-2+j,j+j+i-1)) {
            // cout<<i<<endl;
            return true;
        }
    }
    return false;
}

int main( ){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>a>>b>>t;
    cin>>s;
    if(s[0]=='w') toright[0]=b+1;
    else toright[0]=1;
    For(i,1,n) {
        if(s[i]=='w') toright[i]=toright[i-1]+b+1;
        else toright[i]=toright[i-1]+1;
    }
    toleft[0]=toright[0];
    for(int i=n-1;i>=1;i--){
        toleft[i]=toleft[(i+1)%n]+1;
        if(s[i]=='w') toleft[i]+=b;
    }
    long long high = n+1;
    long long low = 1;
    // cout<<toright[0]<<endl;
    // cout<<can(4)<<endl;
    // return 0;
    while(high>low){
        long long chs = (high+low)>>1;
        // cout<<chs<<endl;
        if(can(chs)) low=chs+1;
        else high=chs;
    }
    cout<<low-1;
}