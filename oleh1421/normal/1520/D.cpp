#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'

using namespace std;
const int N=200010;
const int A=10000001;
void solve(){
    map<int,int>mp;
    int n;cin>>n;
    ll res=0;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        res+=(mp[x-i]++);
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