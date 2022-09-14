//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
const ll mod=1000000007ll;
const int A=1000100;
int pref[N];
int p[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
    pref[0]=0;
    for (int i=1;i<=n;i++) pref[i]=max(pref[i-1],p[i]);
    vector<int>ans;
    for (int i=n;i>=1;i--){
        int j=i;
        while (p[j]!=pref[i]) j--;
        for (int t=j;t<=i;t++) ans.push_back(p[t]);
        i=j;
    }
    for (int i:ans) cout<<i<<" ";
    cout<<endl;


}
int32_t main()
{
//    srand(time(NULL));
//    freopen("subset.in","r",stdin);
//    freopen("subset.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*

4 3 5

*/