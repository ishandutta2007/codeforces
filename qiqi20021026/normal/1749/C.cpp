#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for (int &x:a) cin>>x;
    sort(a.begin(),a.end());
    auto check=[&](int k)
    {
        int i=1,l=0,r=n-1;
        while (l<=r){
            while (l<=r&&a[r]>k-i+1) --r;
            if (l>r) break;
            --r;
            ++l;
            ++i;
        }
        return i>k;
    };
    for (int k=n;k;--k) if (check(k)){
        cout<<k<<'\n';
        return;
    }
    cout<<0<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    int t; cin>>t;
    while (t--) solve();
}