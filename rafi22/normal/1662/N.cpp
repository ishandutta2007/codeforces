#include <bits/stdc++.h>
#pragma GCC target ("avx2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

using namespace std;

#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ll long long
ll mod=1000000007;
int inf=1000000007;
ll infl=1000000000000000007;

const int N=1507;

ll x[N*N+7];
ll y[N*N+7];
ll row[N],col[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,p;
    cin>>n;
    ll tot=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            cin>>p;
            x[p]=i,y[p]=j;
            tot+=(n-i)*(n-j);
        }
    }
    ll cnt=0;
    for(ll i=1;i<=n*n;i++)
    {
        cnt+=row[x[i]]*col[y[i]];
        row[x[i]]++;
        col[y[i]]++;
    }
    cout<<2*tot-cnt;

    return 0;
}