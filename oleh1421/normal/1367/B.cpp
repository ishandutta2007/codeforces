//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef unsigned long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=300010;
int cnt[2];
void solve(){
    int n;cin>>n;
    cnt[0]=cnt[1]=0;
    for (int i=0;i<n;i++){
        int x;cin>>x;
        if (x%2!=i%2) cnt[x%2]++;
    }
    if (cnt[0]!=cnt[1]) cout<<-1<<endl;
    else cout<<cnt[0]<<endl;
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