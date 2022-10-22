#include <bits/stdc++.h>
#define int int64_t
#define loop(i,s,e) for(int i=s;i<e;i++)
#define vi vector<int>
#define pb push_back
using namespace std;
const int MOD = 998244353;

void add(int &a, int b){
    a = (a+b)%MOD;
}
int32_t main(){
    int n; cin>>n;
    vi ten(n+1,1);
    loop(i,1,n+1) ten[i] = (ten[i-1] * 10) % MOD;
    vi ans(n,0);
    ans[n-1] = 10;
    loop(k,1,n){
        int v = ((n - (k+2) + 1) * 81)%MOD;
        v = (v * ten[n-(k+2)+1]) % MOD;
        add(ans[k-1], v);
        v = (2 * 9 * ten[n-(k+1)+1]) % MOD;
        add(ans[k-1], v);
    }
    loop(i,0,n) cout<<ans[i]<<(i<n-1?" ":"");
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
1000

(n - (k+2)+1) * 9 * 9 * 10^(n-(k+2)+1)
2 * 9 * 10 ^(n-(k+1)+1)
*/