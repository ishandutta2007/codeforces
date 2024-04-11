//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse,avx,avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 rnd(time(NULL));
const int N=200100;
int a[N];
void solve(int Case){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<int>ans;
    for (int i=1;i<=n;i++){
        int j=i;
        while (j+1<=n && a[j+1]==a[i]) j++;
        if (i==j){
            cout<<-1<<endl;
            return;
        }
        ans.push_back(j);
        for (int t=i;t<j;t++) ans.push_back(t);
        i=j;
    }
    for (int i:ans) cout<<i<<" ";
    cout<<endl;




}
int32_t main() {
//    freopen("seabattle.in","r",stdin);
//    freopen("seabattle.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt=1;
    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}