#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[1000001];
int main()
{
    ll n,m,k;cin>>n>>m>>k;
    for (int i=0;i<n;i++) cin>>a[i];
    vector<ll>b;
    for (int i=0;i<n-1;i++){
        b.push_back(a[i+1]-a[i]);
    }
    ll sum=a[n-1]-a[0];
    //cout<<sum<<endl;
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    for (int i=1;i<k;i++){
        sum-=b[i-1];
    }
    cout<<sum+k;
    return 0;
}