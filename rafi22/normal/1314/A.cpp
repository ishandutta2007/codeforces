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

pair<int,int> a[200007];
int t[200007];

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
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i].st;
        for(int i=1;i<=n;i++) cin>>a[i].nd;
        sort(a+1,a+n+1);
        multiset<int>key;
        int act=a[1].st,sum=0;
        key.insert(a[1].nd);
        sum=a[1].nd;
        for(int i=2;i<=n;i++)
        {
            while(sz(key)>0&&act<a[i].st)
            {
                int x=*(--key.end());
               // cout<<x<<" "<<act<<endl;
                sum-=x;
                key.erase(key.find(x));
                ans+=sum;
                act++;
            }
            key.insert(a[i].nd);
            act=a[i].st;
            sum+=a[i].nd;
        }
        while(sz(key)>0)
        {
            int x=*(--key.end());
           // cout<<x<<" "<<act<<endl;
            sum-=x;
            key.erase(key.find(x));
            ans+=sum;
            act++;
        }
        cout<<ans;
    }

    return 0;
}