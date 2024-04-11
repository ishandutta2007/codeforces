#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=1000010;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    string s;cin>>s;
    vector<int>v,u;
    for (int i=0;i<n;i++){
        if (s[i]=='B') v.push_back(a[i+1]);
        else u.push_back(a[i+1]);
    }
    sort(v.begin(),v.end());
    sort(u.begin(),u.end());
    for (int i=0;i<v.size();i++){
        if (v[i]<=i){
            cout<<"NO\n";
            return;
        }
    }
    for (int i=0;i<u.size();i++){
        if (u[i]>(int)v.size()+i+1){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";


}
int32_t  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
1
4
1 2 5 2
BRBR
**/