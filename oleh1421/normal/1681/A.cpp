#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const int Lg=20;
const ll mod=998244353;
const ll inv2=(mod+1)/2;
int a[N],b[N];
void solve(){
    int n;cin>>n;
    int mxa=0;
    for (int i=0;i<n;i++) cin>>a[i],mxa=max(mxa,a[i]);
    int m;cin>>m;
    int mxb=0;
    for (int i=0;i<m;i++) cin>>b[i],mxb=max(mxb,b[i]);
    if (mxa>mxb){
        cout<<"Alice\n";
        cout<<"Alice\n";
    } else if (mxa<mxb){
        cout<<"Bob\n";
        cout<<"Bob\n";
    } else {
        cout<<"Alice\n";
        cout<<"Bob\n";
    }


}
int32_t main()
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
3
1 5
2 6
3 4
*/