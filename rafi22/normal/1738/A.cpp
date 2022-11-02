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

int a[100007];

int f(vector<int>a,vector<int>b)
{
    int ans=0;
    if(sz(a)==0) return 0;
    ans+=a[0];
    int c=0;
    if(sz(b)>0)
    {
        ans+=2*b.back();
        b.pop_back();
        c++;
    }
    while(sz(a)>1&&sz(b)>0)
    {
        ans+=2*a.back();
        ans+=2*b.back();
        a.pop_back();
        b.pop_back();
        c++;
    }
    if(sz(a)>1&&c>0)
    {
        ans+=2*a.back();
        a.pop_back();
    }
    for(int i=1;i<sz(a);i++) ans+=a[i];
    for(int i=0;i<sz(b);i++) ans+=b[i];
    return ans;
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
        int n,x;
        cin>>n;
        vector<int>V1,V0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            if(a[i]) V1.pb(x);
            else V0.pb(x);
        }
        sort(all(V1));
        sort(all(V0));
        cout<<max(f(V1,V0),f(V0,V1))<<endl;
    }

    return 0;
}