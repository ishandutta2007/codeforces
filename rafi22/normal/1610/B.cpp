#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int s[200007];

bool is(int l,int r,int x)
{
    if(r<=l) return 1;
    if(s[l]==s[r]) return is(l+1,r-1,x);
    if(x==0)
    {
        return is(l+1,r,s[l])|is(l,r-1,s[r]);
    }
    else
    {
        if(s[l]==x) return is(l+1,r,x);
        if(s[r]==x) return is(l,r-1,x);
        return 0;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>s[i];
        if(is(1,n,0)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}