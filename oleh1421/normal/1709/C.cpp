#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//#define y2 y_2
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
#define int ll
typedef long long ll;
typedef long double ld;
const int N=2000010;
ll a[N];
ll pref[N];
ll suf[N];
void solve(){
    string s;cin>>s;
    int cnt=s.size()/2;

    for (int i=0;i<s.size();i++){
        if (s[i]=='(') cnt--;
    }
    int a=-1,b=-1;
    for (int i=0;i<s.size();i++){
        if (s[i]=='?'){
            if (cnt==1) a=i;
            else if (cnt==0) b=i;
            if (cnt>0) s[i]='(';
            else s[i]=')';
            cnt--;
        }
    }
    if (a==-1 || b==-1){
        cout<<"YES\n";
        return;
    }
    swap(s[a],s[b]);
    int sum=0;
    for (auto i:s){
        sum+=(i=='(')-(i==')');
        if (sum<0){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";

}
int32_t main() {
//    freopen("5.034.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
4 3 2000
1 2 100
2 3 1000
2 4 1000
1.27
3,16,27,24,23,46
**/