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

vector<pair<int,int>>ans;
vector<int>res;

void solve(vector<int>a,int x)
{
    if(sz(a)==0) return ;
    int j;
    for(int i=1;i<sz(a);i++)
    {
        if(a[i]==a[0])
        {
            j=i;
            break;
        }
    }
    res.pb(2*j);
    for(int i=1;i<j;i++) ans.pb({x+j+i,a[i]});
    vector<int>b;
    for(int i=1;i<j;i++) b.pb(a[i]);
    reverse(all(b));
    for(int i=j+1;i<sz(a);i++) b.pb(a[i]);
    solve(b,x+2*j);
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
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        bool zle=0;
        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=0;j<n;j++) if(a[i]==a[j]) c++;
            if(c%2) zle=1;
        }
        if(zle)
        {
            cout<<-1<<endl;
            continue;
        }
        ans.clear();
        res.clear();
        solve(a,0);
        cout<<sz(ans)<<endl;
        for(auto x:ans) cout<<x.st<<" "<<x.nd<<endl;
        cout<<sz(res)<<endl;
        for(auto x:res) cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}