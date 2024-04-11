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
    int n,k;cin>>n>>k;
    string s;cin>>s;
    if (s[n-1]=='0'){
        int last=-1;
        for (int j=0;j<n;j++){
            if (s[j]=='1') last=j;
        }
        if (last!=-1){
            if (n-1-last<=k){
                k-=n-1-last;
                swap(s[last],s[n-1]);
            }

        }
    }
    if (s[0]=='0'){
        int f=-1;
        for (int i=1;i<n-1;i++){
            if (s[i]=='1'){
                f=i;
                break;
            }
        }
        if (f!=-1){
            if (f<=k){
                k-=f;
                swap(s[0],s[f]);
            }
        }

    }
    int res=0;
    for (int i=1;i<n;i++){
        res+=(s[i-1]-'0')*10+(s[i]-'0');
    }
    cout<<res<<endl;



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