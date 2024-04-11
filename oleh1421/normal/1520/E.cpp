#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'

using namespace std;
const int N=2000010;
const int A=10000001;
void solve(){
    int n;cin>>n;
    vector<int>v;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        if (c=='*') v.push_back(i);
    }
    if (v.empty()){
        cout<<0<<endl;
        return;
    }
    int cur=0;
    for (int i=0;i<v.size();i++){
        v[i]-=i+1;
        cur+=v[i];
    }

    sort(v.begin(),v.end());
    ll m=v[(int)v.size()/2];
    ll res=0ll;
    for (ll i:v){
        res+=abs(i-m);
    }
    cout<<res<<endl;



}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
5 5 5
6 6 6 6 6
**/