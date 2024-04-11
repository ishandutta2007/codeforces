//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
const int N=200010;
const int A=10000010;
int cnt[N];
int a[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i],cnt[a[i]%m]++;
    int res=0;
    if (cnt[0]) res++;
    if (m%2==0 && cnt[m/2]) res++;
    for (int i=1;i*2<m;i++){
        if (cnt[i]+cnt[m-i]==0) continue;
        if (cnt[i]==cnt[m-i]){
            res++;
            continue;
        }
        res+=abs(cnt[i]-cnt[m-i]);
    }
    cout<<res<<endl;
    for (int i=1;i<=n;i++) cnt[a[i]%m]=0;

}
int main()
{

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/**
4
3
1 1 2
2 2
1 2 10
2 1 10
1

10 3
2

**/