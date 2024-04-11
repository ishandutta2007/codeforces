#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,r,avg;
pair<ll,ll> q[100000];
int main()
{
    cin>>n>>r>>avg;
    avg*=n;
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>q[i].second>>q[i].first;
        sum+=q[i].second;
    }
    ll ans=0;
    sort(q,q+n);
    for(int i=0;i<n && sum<avg;i++){
        if(avg-sum<=r-q[i].second){
            ans+=(avg-sum)*q[i].first;
            sum=avg;
        }
        else{
            ans+=(r-q[i].second)*q[i].first;
            sum+=r-q[i].second;
        }
    }
    cout<<ans;
}