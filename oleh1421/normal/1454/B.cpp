//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;
int cnt[N];
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int ind=0;
    for (int i=1;i<=n;i++){
        if (cnt[a[i]]==1){
            if (!ind || a[ind]>a[i]) ind=i;
        }
    }
    if (ind) cout<<ind<<endl;
    else cout<<-1<<endl;
    for (int i=0;i<=n;i++) cnt[i]=0;



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