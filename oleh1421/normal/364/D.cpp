#include <bits/stdc++.h>
//#define endl '\n'
const long long mod=1000000007;
typedef long long ll;
using namespace std;
mt19937_64 rng(time(NULL));
ll a[3000001];
ll b[3000001];
map<ll,ll>mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    ll maxx=0;
    for (int it=1;it<=10;it++){
        ll x=a[rng()%n+1];
        mp.clear();
        for (int i=1;i<=n;i++){
            mp[__gcd(a[i],x)]++;
        }
        vector<ll>v;
        for (ll i=1ll;i*i<=x;i++){
            if (x%i) continue;
            if (i>maxx) v.push_back(i);
            if ((x/i)>maxx) v.push_back(x/i);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for (ll x:v){
            int cnt=0;
            for (auto cur:mp){
                if (cur.first%x==0) cnt+=cur.second;
            }
            if (cnt+cnt>=n) {
                maxx=x;
                break;
            }
        }
    }
    cout<<maxx;
    return 0;
}