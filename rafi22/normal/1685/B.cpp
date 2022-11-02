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
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        string s;
        cin>>s;
        int n=sz(s);
        int ca=0,cb=0;
        for(auto x:s)
        {
            if(x=='A') ca++;
            else cb++;
        }
        if(ca!=a+c+d||cb!=b+c+d)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int p=0,S=0;
        vector<int>Va,Vb;
        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[i-1]) p++;
            else
            {
                if(p%2==0) S+=p/2;
                else
                {
                    if(s[i-1]=='B') Va.pb(p/2+1);
                    else Vb.pb(p/2+1);
                }
                p=0;
            }
        }
        if(p%2==0) S+=p/2;
        else
        {
            if(s[n-1]=='B') Va.pb(p/2+1);
            else Vb.pb(p/2+1);
        }
        sort(all(Va));
        sort(all(Vb));
        for(auto x:Va)
        {
            if(c>=x) c-=x;
            else S+=x-1;
        }
        for(auto x:Vb)
        {
            if(d>=x) d-=x;
            else S+=x-1;
        }
        if(c+d<=S) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}