//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
using namespace std;
const int N=300010;
int a[N];
int n;
void solve(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (a[1]<a[n]) cout<<"YES\n";
    else cout<<"NO\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
1
5
2 5 3 4 1

*/