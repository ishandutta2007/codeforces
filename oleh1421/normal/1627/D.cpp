#pragma GCC optimize("Ofast")
//#pragma GCC optimization("unroll-loops")
//#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N=1000010;
const int K=510;
const ll mod=998244353;
bool used[N];
int cnt[N];
void solve(){
    int n;cin>>n;
    int A=0;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        used[x]=true;
        A=max(A,x);
    }
    for (int i=1;i<=A;i++){
        cnt[i]=0;
        for (int j=i;j<=A;j+=i) cnt[i]+=used[j];
    }
    int res=0;
    for (int i=1;i<=A;i++){
        if (cnt[i]==0) continue;
        bool ok=true;
        for (int j=i*2;j<=A;j+=i){
            if (cnt[j]==cnt[i]) ok=false;
        }
        res+=ok;
    }
    cout<<res-n<<endl;


}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;

}
/**
ababababa
2
1 5 c
2 1 7 aba
**/