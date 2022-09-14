#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
//#define inf 10000000000000001ll
//#define fi first
//#define se second
typedef long long ll;
using namespace std;
ll w[500001];
void add(int l,int r,ll x){
    if (l>r) return;
    w[l]+=x*1ll;
    w[r+1]-=x*1ll;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    vector<int>x(m);
    for (int i=1;i<=m;i++){
        cin>>x[i-1];
    }
    for (int i=1;i<m;i++){
        int a=x[i-1];
        int b=x[i];
        if (a>b) swap(a,b);
        if (a==b) continue;
        add(1,a-1,b-a);
        add(b+1,n,b-a);
        add(a,a,b-1);
        add(b,b,a);
        add(a+1,b-1,b-a-1);
    }
    ll sum=0ll;
    for (int i=1;i<=n;i++){
        sum+=w[i]*1ll;
        cout<<sum<<" ";
    }
    return 0;
}