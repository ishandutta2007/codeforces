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
bool is[100007];


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
        for(int i=1;i<=n;i++) is[i]=0;
        vector<int>V;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]<=n&&!is[a[i]]) is[a[i]]=1;
            else V.pb(a[i]);
        }
        sort(all(V));
        bool bad=0;
        int ans=0;
        for(int i=n;i>0;i--)
        {
            if(is[i]) continue;
            if(V.back()/2+V.back()%2-1<i) bad=1;
            V.pop_back();
            ans++;
        }
        if(bad) cout<<-1<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}