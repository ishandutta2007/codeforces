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

const int N=200007;

int a[N];
int p[N];

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
        for(int i=1;i<=n;i++) cin>>a[i];
        bool ans=1;
        vector<pair<int,int>>Q;
        multiset<int>S;
        for(int i=1;i<=n;i++)
        {
            p[i]=p[i-1]+a[i];
            while(sz(Q)>0&&Q.back().st<a[i])
            {
                S.erase(S.find(p[Q.back().nd]));
                Q.pop_back();
            }
            Q.pb({a[i],i});
            S.insert(p[i]);
            if(sz(S)>0&&p[i]>*S.begin()) ans=0;
        }
        Q.clear();
        S.clear();
        reverse(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        {
            p[i]=p[i-1]+a[i];
            while(sz(Q)>0&&Q.back().st<a[i])
            {
                S.erase(S.find(p[Q.back().nd]));
                Q.pop_back();
            }
            Q.pb({a[i],i});
            S.insert(p[i]);
            if(sz(S)>0&&p[i]>*S.begin()) ans=0;
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}