#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(long long i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000001
#define pb push_back

long long n,p,tot;
string s;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>p;
    tot=0;
    long long cur=1;
    while(n--)
    {
        cin>>s;
        if(s.size()!=4) tot+=cur;
        cur*=2;
    }
    long long ans=0;
    while(tot)
    {
        if(tot&1) ans+=p/2;
        ans+=p*(tot/2);
        tot/=2;
    }
    cout<<ans;
}