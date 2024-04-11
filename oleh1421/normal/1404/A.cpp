#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;

void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    int cnt0=0;
    int cnt1=0;
    for (int i=0;i<k;i++){
        bool ok0=false;
        bool ok1=false;
        for (int j=i;j<n;j+=k){
            if (s[j]=='1') ok1=true;
            if (s[j]=='0') ok0=true;
        }
        if (ok1 && ok0){
            cout<<"NO\n";
            return;
        } else if (ok1) cnt1++;
        else if (ok0) cnt0++;
    }
    if (cnt0>k/2 || cnt1>k/2) cout<<"NO\n";
    else cout<<"YES\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/*
7
10 10 8 5 3
*/