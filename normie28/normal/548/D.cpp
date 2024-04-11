#include <bits/stdc++.h>
using namespace std;
#define fl(i,a,n) for (int i=a;i<n;i++)
#define rfl(i,a,n) for (int i=n-1;i>=a;i--)
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
template <typename T> T gcd(T a, T b) { return b != 0 ? gcd(b, a % b) : a; }
int main()
{
    ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    ll a[n+1];
    fl(i,1,n+1)
    {
        cin >> a[i];
    }
    stack<pair<ll,ll>>s;
    ll l[n+1];
    s.push(mp(a[1],1));
    l[1]=0; 
    fl(i,2,n+1)
    {
        while(s.size()>0&&s.top().f>=a[i])
        {
            s.pop();
        }
        if(s.size()==0)
        {
            s.push(mp(a[i],i));
            l[i]=i-1;
        }
        else
        {
            l[i]=i-s.top().s-1;
            s.push(mp(a[i],i));
        }
    }
    ll r[n+1];
    while(s.size()!=0)
    {
        s.pop();
    }
    s.push(mp(a[n],n));
    r[n]=0; 
    for(int i=n-1;i>=1;i--)
    {
        while(s.size()>0&&s.top().f>=a[i])
        {
            s.pop();
        }
        if(s.size()==0)
        {
            s.push(mp(a[i],i));
            r[i]=n-i;
        }
        else
        {
            r[i]=abs(i-s.top().s)-1;
            s.push(mp(a[i],i));
        }
    }
    ll sum[n+1];
    fl(i,1,n+1)
    {
        sum[i]=l[i]+r[i]+1;
    }
    ll final[n+1];
    memset(final,-1,sizeof(final));
    fl(i,1,n+1)
    {
        final[sum[i]]=max(final[sum[i]],a[i]);
    }
    for(int i=n-1;i>=1;i--)
    {
        if(final[i]==-1)
        {
            final[i]=final[i+1];
        }
    }
    for(int i=n-1;i>=1;i--)
    {
        final[i]=max(final[i],final[i+1]);
    }
    fl(i,1,n+1)
    {
        cout << final[i] << " ";
    }
}