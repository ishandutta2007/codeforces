#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=1000000000+7;
const int N=100010;
ll a[N];
int cnt[N][30];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<ll>p;
    ll x=(a[1]*a[2])/__gcd(a[1],a[2]);
    ll d=2ll;
    while (d*d<=x){
        if (x%d==0){
            p.push_back(d);
            while (x%d==0) x/=d;
        }
        d++;
    }
    if (x>1) p.push_back(x);
    for (int i=1;i<=n;i++){
        for (int j=0;j<p.size();j++){
            while (a[i]%p[j]==0){
                cnt[i][j]++;
                a[i]/=p[j];
            }
        }
    }
    ll res=1ll;
    for (int i=0;i<p.size();i++){
        vector<int>v;
        for (int j=1;j<=n;j++) v.push_back(cnt[j][i]);
        nth_element(v.begin(),v.begin()+1,v.end());
        for (int j=0;j<v[1];j++) res*=p[i];
    }
    cout<<res<<endl;
    return 0;
}