#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--){
        int n; cin>>n;
        vector<int> a(n);
        for (int &x:a) cin>>x;
        sort(a.begin(),a.end());
        cout<<(unique(a.begin(),a.end())==a.end()?"YES":"NO")<<'\n';
    }
}