#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
const ll mod=998244353;
const int N=1500000;
void solve(){
    int n;cin>>n;

    for (int i=(n%3==0 || n%3==2);n>0;i++){
        int cur=i%2+1;
        cout<<cur;
        n-=cur;
    }
    cout<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//2121
//121
//2
//
//1 2

/**

R,S

RSAxT
SxART
xSART


**/