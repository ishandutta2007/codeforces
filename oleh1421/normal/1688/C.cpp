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
const int N=5000100;
const ll mod=1000000007;
ll a[N];
int cnt[27];
void solve(int Case){
    int n;cin>>n;
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=2*n+1;i++){
        string s;cin>>s;
        for (auto j:s){
            cnt[j-'a']++;
        }
    }
    for (int i=0;i<26;i++){
        if (cnt[i]%2){
            cout<<char(i+'a')<<endl;
            return;
        }
    }



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
/**
1
3
1 -1 1
**/