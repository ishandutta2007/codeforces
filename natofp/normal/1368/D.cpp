#include <bits/stdc++.h>
#define ll long long int
#define pb push_back


using namespace std;

ll cnt[33];
ll ans[222222];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    ll x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        ll wsk = 0;
        while(x)
        {
            if(x%2==1) cnt[wsk]++;
            wsk++;
            x/=2;
        }
    }
    ll wsk = 31;
    ll res = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=25;j>=0;j--)
        {
            if(cnt[j]>0)
            {
                cnt[j]--;
                ans[i]+=(1<<j);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        res += ans[i]*ans[i];
    }
    cout<<res;

    return 0;
}