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

long long n,m[22],r[22],cnt,tot;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    tot=1;
    For(i,0,n)
    {
        cin>>m[i];
        tot*=m[i]/__gcd(tot,m[i]);
    }
    For(i,0,n) cin>>r[i];
    For(i,0,tot)
    {
        bool flag=false;
        For(j,0,n) if(i%m[j]==r[j])
        {
            flag=true;
            break;
        }
        if(flag) cnt++;
    }
    cout<<cnt*1.0/tot;
}