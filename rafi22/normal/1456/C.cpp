#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int a[500007];
multiset<int>q;

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
        int n,k,ans=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n,greater<int>());
        for(int i=0;i<=k;i++) q.insert(0);
        for(int i=1;i<=n;i++)
        {
            int x=*(--q.end());
            q.erase(--q.end());
            q.insert(x+a[i]);
            ans+=x;
        }
        cout<<ans;
    }

    return 0;
}