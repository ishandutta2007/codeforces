#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k;cin>>n>>k;
    vector<ll>v;
    for (int i=1;i<=sqrt(n);i++){
        if (n%i==0){
            v.push_back(i);
            if (i!=sqrt(n)) v.push_back(n/i);
        }
    }
    ll ans,x;
    ans=INT_MAX;
    for (int j=0;j<v.size();j++){
            //cout<<v[j]<<" ";
            ll ost=n/v[j];
            if (ost>=k) continue;
            x=v[j]*k+ost;
           //cout<<v[j]<<" "<<x<<endl;
            ans=min(ans,x);
    }
    cout<<ans;
    return 0;
}