//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef unsigned long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=300010;
int cnt[30];


void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    for (auto i:s) cnt[i-'a']++;
    int res=0;
    for (int d=1;d<=k;d++){
        if (k%d) continue;
        for (int i=1;i*d<=n;i++){
            int sum=0;
            for (int j=0;j<26;j++) sum+=(cnt[j]/i);
            if (sum>=d) res=max(res,i*d);
        }
    }
    for (int i=0;i<26;i++) cnt[i]=0;
    cout<<res<<endl;
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
abba
3
1 0 1
*/