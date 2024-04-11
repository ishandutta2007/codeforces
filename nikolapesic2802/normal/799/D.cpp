#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;


int add(int a, int b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

ll pw(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
ll v[100002];

map<pair<ll, pair<ll, ll> >, int>mp;
int getAns(ll a,ll b,ll h,ll w,ll n)
{
	mp.clear();
	if(h >= a && w >= b)
    {
        return 0;
    }
    else
    {
        if(h >= a)
        {
            int ans = 0;
            while(n && w < b)
                w *= v[n], --n, ++ans;
            if(w >= b)
                return ans;
            else
                return -1;
        }
        else
        {
            if(w >= b)
            {
                int ans = 0;
                while(n && h < a)
                    h *= v[n], --n, ++ans;
                if(h >= a)
                    return ans;
                else
                    return -1;
            }
            else
            {
                 queue<pair<ll, pair<ll, ll> > >q;
                 q.push({h, {w, n}});
                 ll ans = -1;
                 while(!q.empty())
                 {
                     pair<ll, pair<ll, ll> > x = q.front();
                     q.pop();
                     if(n - x.se.se >= 20)
                     {
                        if(mp[x])
                            continue;
                        mp[x] = 1;
                     }
                     if(x.fi >= a && x.se.fi >= b)
                     {
                         if(ans == -1)
                            ans = n - x.se.se;
                         else
                            ans = min(ans, n - x.se.se);
                     }
                     else
                         if(x.fi >= a)
                         {
                             while(x.se.se && x.se.fi < b)
                                x.se.fi *= v[x.se.se], --x.se.se;
                             if(x.se.fi >= b)
                             {
                                 if(ans == -1)
                                    ans = n - x.se.se;
                                 else
                                    ans = min(ans, n - x.se.se);
                             }
                         }
                         else
                            if(x.se.fi >= b)
                            {
                                while(x.se.se && x.fi < a)
                                    x.fi *= v[x.se.se], --x.se.se;
                                if(x.fi >= a)
                                {
                                    if(ans == -1)
                                        ans = n - x.se.se;
                                    else
                                        ans = min(ans, n - x.se.se);
                                }
                            }
                            else
                            {
                                if(x.se.se == 0)
                                    continue;
                                q.push({x.fi * v[x.se.se], {x.se.fi, x.se.se - 1}});
                                q.push({x.fi, {x.se.fi * v[x.se.se], x.se.se - 1}});
                            }
                 }
                 return ans;
            }
        }
    }
}
ll a, b, h, w, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> h >> w >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v+1, v+n+1);
    int a1=getAns(a,b,h,w,n),a2=getAns(b,a,h,w,n);
    if(a1==-1)
    	cout << a1;
    else
    if(a2==-1)
    	cout << a2;
    else
    cout << min(a1,a2);
    return 0;
}