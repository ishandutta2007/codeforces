//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef unsigned long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=300010;
ll cnt[20];

void solve(){
    ll k;cin>>k;
    for (int i=0;i<10;i++){
        cnt[i]=1;
    }
    if (k>1){
        bool ok=false;
        while (!ok){
            for (int i=0;i<10;i++){
                cnt[i]++;
                ll mult=1ll;
                for (int j=0;j<10;j++){
                    mult*=cnt[j];
                }
                if (mult>=k){
                    ok=true;
                    break;
                }
            }
        }
    }
    string s="codeforces";
    for (int i=0;i<10;i++){
        for (int j=0;j<cnt[i];j++) cout<<s[i];
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*
1
4
0 3 3 1
*/